#!/bin/sh
# usage: hello
# Prints a customized greeting

if [ $# -ne 0 ] ; then
     echo 1>&2 "usage: $0"
     exit 1
fi

echo "Hello $(id -nu)."
