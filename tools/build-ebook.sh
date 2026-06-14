#!/bin/sh

set -eu

OUT_DIR=${OUT_DIR:-ebook/build}
MANIFEST=${MANIFEST:-ebook/manifest.txt}
METADATA=${METADATA:-ebook/metadata.yaml}
OUT_BASENAME=${OUT_BASENAME:-cpp-kurs}

mkdir -p "$OUT_DIR"

combined="$OUT_DIR/$OUT_BASENAME.md"
pdf="$OUT_DIR/$OUT_BASENAME.pdf"
epub="$OUT_DIR/$OUT_BASENAME.epub"

: > "$combined"

while IFS= read -r file; do
    case "$file" in
        ""|\#*)
            continue
            ;;
    esac

    if [ ! -f "$file" ]; then
        echo "Missing ebook source: $file" >&2
        exit 1
    fi

    printf '\n\n<!-- source: %s -->\n\n' "$file" >> "$combined"
    sed 's#](../#](#g' "$file" >> "$combined"
done < "$MANIFEST"

echo "Wrote $combined"

if command -v pandoc >/dev/null 2>&1; then
    pandoc "$combined" \
        --metadata-file "$METADATA" \
        --standalone \
        --toc \
        --number-sections \
        --pdf-engine=xelatex \
        -o "$pdf"
    echo "Wrote $pdf"

    pandoc "$combined" \
        --metadata-file "$METADATA" \
        --standalone \
        --toc \
        -o "$epub"
    echo "Wrote $epub"
else
    echo "pandoc not found; generated Markdown only"
fi
