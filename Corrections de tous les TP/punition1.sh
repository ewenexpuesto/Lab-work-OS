#!/bin/sh
# usage: punition1.sh n str

if [ $# -ne 2 ] ; then
      echo >&2 "usage: $0 n str" ; exit 1
fi

n="$1"
line="$2"

i=0
while [ $i -lt $n ] ; do
      echo "$line"
      i=$((i+1))
done
