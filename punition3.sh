#!/bin/sh
#
#usage: punition1.sh n word

#dans cet ordre pour la suite
n="$1"
m="$2"
w="$3"
str=""

i=0

while [ $i -lt $m ] ; do
    str="$str $w"
    i=$((i+1))
done
punition1.sh "$n" "$str"
