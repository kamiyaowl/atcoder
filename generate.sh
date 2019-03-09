#!/bin/sh

if [ $# -ne 1 ]; then
    echo "./initialize.sh [dst_path] [src_path]" 1>&2
    echo " - dst_path : ex. abc123" 1>&2
    echo " - src_path : (option) ex. ./template" 1>&2
    exit 1
fi

dst_path=$1
src_path=$2

if [ $# -ne 2 ]; then
    src_path="./template"
fi

if [ -d $dst_path ]; then
    echo "$dst_path always exists."
    exit 1
fi

echo "$src_path -> $dst_path/a"
echo "$src_path -> $dst_path/b"
echo "$src_path -> $dst_path/c"
echo "$src_path -> $dst_path/d"

mkdir "$dst_path"
cp -ri "$src_path" "$dst_path/a"
cp -ri "$src_path" "$dst_path/b"
cp -ri "$src_path" "$dst_path/c"
cp -ri "$src_path" "$dst_path/d"

exit 0