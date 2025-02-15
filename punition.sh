#!/bin/sh
#
#usage: trop long voir TP

n="$1"
m="$2"
w="$3"

if [ $# -eq 0 ] ; then
    n=10; m=3; w='Je ne bavarde pas en cours !'
elif [ $# -eq 1 ] ; then
    n=10; m=3
elif [ $# -eq 2 ] ; then
    n=10; w='Je ne bavarde pas en cours !'
fi
punition3.sh "$n" "$m" "$w"