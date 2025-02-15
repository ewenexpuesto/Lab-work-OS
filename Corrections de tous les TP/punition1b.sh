#!/bin/sh
# usage: punition1b.sh [n] str

if [ $# -eq 1 ] ; then
      set -- 5 "$1" # adding 5 as the first argument
fi
if [ $# -ne 2 ] ; then
      echo >&2 "usage: $0 [n] str" ; exit 1
fi

n="$1"
line="$2"

i=0
while [ $i -lt $n ] ; do
      echo "$line"
      i=$((i+1))
done
