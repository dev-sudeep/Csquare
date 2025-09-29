#!/bin/bash
CC=${CC:-cc}   # default cc, or clang/gcc
if $CC --version 2>/dev/null | grep -qi clang; then
    CFG="$HOME/.clangrc"
    echo "🔧 Configuring clang → $CFG"
elif $CC --version 2>/dev/null | grep -qi gcc; then
    CFG="$HOME/.bashrc"   # or ~/.zshrc depending on your shell
    echo "🔧 Configuring gcc → appending CFLAGS to $CFG"
else
    echo "❌ Unknown compiler: $CC"
    exit 1
fi

# Generate include flags
flags=""
for dir in $(find ./include -type f); do
    abs=$(realpath "$dir")
    flags="$flags -I$abs"
done

# Apply depending on compiler
if [[ "$CFG" == *clangrc ]]; then
    {
        echo "# >>> auto-include >>>"
        echo "$flags"
        echo "# <<< auto-include <<<"
    } >> "$CFG"
else
    {
        echo "# >>> auto-include >>>"
        echo "export CFLAGS=\"\$CFLAGS $flags\""
        echo "export CPPFLAGS=\"\$CPPFLAGS $flags\""
        echo "# <<< auto-include <<<"
    } >> "$CFG"
fi
