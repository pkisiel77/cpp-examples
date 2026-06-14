#!/usr/bin/env python3

from __future__ import annotations

import os
import re
import sys
from pathlib import Path
from urllib.parse import unquote


ROOT = Path(__file__).resolve().parents[1]
EXCLUDED_DIRS = {".git"}
LINK_PATTERN = re.compile(r"!?\[[^\]]*\]\(([^)]+)\)")


def is_external(target: str) -> bool:
    return (
        "://" in target
        or target.startswith("#")
        or target.startswith("mailto:")
        or target.startswith("tel:")
    )


def markdown_files() -> list[Path]:
    files: list[Path] = []
    for path in ROOT.rglob("*.md"):
        if any(part in EXCLUDED_DIRS for part in path.parts):
            continue
        files.append(path)
    return sorted(files)


def normalize_target(raw_target: str) -> str:
    target = raw_target.strip()
    if not target:
        return target

    if target.startswith("<") and target.endswith(">"):
        target = target[1:-1].strip()

    if " " in target:
        target = target.split()[0]

    target = target.split("#", 1)[0]
    return unquote(target)


def check_file(path: Path) -> list[str]:
    errors: list[str] = []
    text = path.read_text(encoding="utf-8")
    in_fenced_code = False

    for line_no, line in enumerate(text.splitlines(), start=1):
        stripped = line.lstrip()
        if stripped.startswith("```") or stripped.startswith("~~~"):
            in_fenced_code = not in_fenced_code
            continue

        if in_fenced_code:
            continue

        for match in LINK_PATTERN.finditer(line):
            if line[: match.start()].count("`") % 2 == 1:
                continue

            raw_target = match.group(1)
            target = normalize_target(raw_target)

            if not target or is_external(target):
                continue

            if target.startswith("/"):
                errors.append(f"{path.relative_to(ROOT)}:{line_no}: absolute link: {raw_target}")
                continue

            resolved = (path.parent / target).resolve()

            try:
                resolved.relative_to(ROOT)
            except ValueError:
                errors.append(f"{path.relative_to(ROOT)}:{line_no}: link leaves repo: {raw_target}")
                continue

            if not resolved.exists():
                errors.append(f"{path.relative_to(ROOT)}:{line_no}: missing link target: {raw_target}")

    return errors


def main() -> int:
    errors: list[str] = []
    for path in markdown_files():
        errors.extend(check_file(path))

    if errors:
        print("Broken Markdown links:")
        for error in errors:
            print(f"- {error}")
        return 1

    print("All Markdown links passed")
    return 0


if __name__ == "__main__":
    os.chdir(ROOT)
    sys.exit(main())
