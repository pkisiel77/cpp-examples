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


def check_language(
    label: str,
    metadata_path: str,
    front_matter_path: str,
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

    return errors


def main() -> int:
    errors: list[str] = []

    errors.extend(
        check_language(
            label="PL",
            metadata_path="ebook/metadata.yaml",
            front_matter_path="ebook/front-matter.md",
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
