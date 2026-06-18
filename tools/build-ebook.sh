#!/bin/sh

set -eu

OUT_DIR=${OUT_DIR:-ebook/build}
EBOOK_LANG=${EBOOK_LANG:-pl}

case "$EBOOK_LANG" in
    pl)
        DEFAULT_MANIFEST=ebook/manifest.txt
        DEFAULT_METADATA=ebook/metadata.yaml
        DEFAULT_OUT_BASENAME=cpp-kurs
        ;;
    en)
        DEFAULT_MANIFEST=ebook/en/manifest.txt
        DEFAULT_METADATA=ebook/en/metadata.yaml
        DEFAULT_OUT_BASENAME=cpp-course-en
        ;;
    *)
        echo "Unsupported EBOOK_LANG: $EBOOK_LANG" >&2
        exit 1
        ;;
esac

MANIFEST=${MANIFEST:-$DEFAULT_MANIFEST}
METADATA=${METADATA:-$DEFAULT_METADATA}
OUT_BASENAME=${OUT_BASENAME:-$DEFAULT_OUT_BASENAME}

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
