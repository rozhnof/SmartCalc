#!/bin/sh

files=$(find . | grep '[.]h')

for i in $files; do
    header_name=$(basename "$i")
    header_name="#include \"$header_name\"\n\n"

    new_name=$(echo "$i" | sed 's/[.]h/.cpp/')
    echo "$new_name"
    sed -i '1s/.*/'"$header_name"'/' "$new_name"
done