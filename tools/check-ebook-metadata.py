#!/usr/bin/env python3

from __future__ import annotations

import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


def read(relative: str) -> str:
    return (ROOT / relative).read_text(encoding="utf-8")


def field(text: str, name: str, source: str) -> str:
    match = re.search(rf'^{re.escape(name)}:\s*"?([^"\n]+)"?\s*$', text, re.MULTILINE)
    if not match:
        raise ValueError(f"{source}: missing field {name}")
    return match.group(1)


def require_contains(text: str, needle: str, source: str) -> list[str]:
    if needle not in text:
        return [f"{source}: missing {needle!r}"]
    return []


def check_manifest(manifest_path: str, expected_first: str) -> list[str]:
    errors: list[str] = []
    manifest = ROOT / manifest_path
    entries: list[str] = []
    seen: dict[str, int] = {}

    for line_no, line in enumerate(manifest.read_text(encoding="utf-8").splitlines(), start=1):
        entry = line.strip()
        if not entry or entry.startswith("#"):
            continue

        entries.append(entry)
        if entry in seen:
            errors.append(
                f"{manifest_path}:{line_no}: duplicate source: {entry} "
                f"(first listed on line {seen[entry]})"
            )
        else:
            seen[entry] = line_no

        path = ROOT / entry

        if not path.exists():
            errors.append(f"{manifest_path}:{line_no}: missing source: {entry}")
            continue

        if not path.is_file():
            errors.append(f"{manifest_path}:{line_no}: source is not a file: {entry}")
            continue

        if path.stat().st_size == 0:
            errors.append(f"{manifest_path}:{line_no}: empty source: {entry}")

    if not entries:
        errors.append(f"{manifest_path}: manifest has no source files")
    elif entries[0] != expected_first:
        errors.append(
            f"{manifest_path}: first source should be {expected_first}, "
            f"got {entries[0]}"
        )

    return errors


def check_language(
    label: str,
    metadata_path: str,
    front_matter_path: str,
    manifest_path: str,
    expected_first_source: str,
    expectations: list[tuple[str, str]],
) -> list[str]:
    errors: list[str] = []

    metadata = read(metadata_path)
    front_matter = read(front_matter_path)

    metadata_version = field(metadata, "version", metadata_path)
    metadata_date = field(metadata, "date", metadata_path)
    front_version = field(front_matter, "version", front_matter_path)
    front_date = field(front_matter, "date", front_matter_path)

    if metadata_version != front_version:
        errors.append(
            f"{label}: version mismatch: {metadata_path}={metadata_version}, "
            f"{front_matter_path}={front_version}"
        )

    if metadata_date != front_date:
        errors.append(
            f"{label}: date mismatch: {metadata_path}={metadata_date}, "
            f"{front_matter_path}={front_date}"
        )

    changelog = read("ebook/CHANGELOG.md")
    if not re.search(
        rf"^## {re.escape(metadata_version)} - \d{{4}}-\d{{2}}-\d{{2}}$",
        changelog,
        re.MULTILINE,
    ):
        errors.append(
            f"ebook/CHANGELOG.md: missing changelog header for {metadata_version}"
        )

    for path, template in expectations:
        errors.extend(require_contains(read(path), template.format(version=metadata_version), path))

    errors.extend(check_manifest(manifest_path, expected_first_source))

    return errors


def main() -> int:
    errors: list[str] = []

    errors.extend(
        check_language(
            label="PL",
            metadata_path="ebook/metadata.yaml",
            front_matter_path="ebook/front-matter.md",
            manifest_path="ebook/manifest.txt",
            expected_first_source="ebook/front-matter.md",
            expectations=[
                ("ebook/README.md", "PL: `{version}`"),
                ("ebook/front-matter.md", "Wersja: `{version}`"),
            ],
        )
    )

    errors.extend(
        check_language(
            label="EN",
            metadata_path="ebook/en/metadata.yaml",
            front_matter_path="ebook/en/front-matter.md",
            manifest_path="ebook/en/manifest.txt",
            expected_first_source="ebook/en/front-matter.md",
            expectations=[
                ("ebook/README.md", "EN: `{version}`"),
                ("ebook/en/README.md", "Current version: `{version}`"),
                ("ebook/en/course-plan.md", "version: `{version}`"),
                ("ebook/en/front-matter.md", "Version: `{version}`"),
            ],
        )
    )

    if errors:
        print("Ebook metadata check failed:")
        for error in errors:
            print(f"- {error}")
        return 1

    print("All ebook metadata checks passed")
    return 0


if __name__ == "__main__":
    sys.exit(main())
