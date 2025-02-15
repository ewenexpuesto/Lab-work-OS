#!/bin/sh
#
#usage: punition2.sh n m word

if [ $# -ne 3 ] ; then
    echo >&2 "usage: $0 <int> <int> <str>" #ne pas oublier de changer la définition
    exit 1
fi

n="$1"
m="$2"
word="$3"

i=0
j=0
while [ $i -lt "$n" ] ; do
    while [ $j -lt "$m" ] ; do
        echo -n "$word "
        j=$((j+1))
    done
    echo "\n"
    i=$((i+1))
    j=0
done