#!/bin/sh
# Usage : 

if [ $# -eq 0 ] ; then
    echo "usage <nauuur>"
    exit 1 # N'importe quoi sauf 0
fi

while read file ; do # Lecture 1 à 1 des noms de fichiers
    if [ ! -e "$file" ] ;
    then
        echo "'$file' does not exist";
    elif [ ! -f "$file" ] ;
    then echo "'$file' is not a regular file";
    elif [ ! -r "'$file' is not readable"] ; # les répertoires existent mais on ne peut pas les lire
    then echo "'$file' is not readable";
    else
        # Cas général : le fichier est lisible, régulier et existe
        for pat in "$@"; do
            nbPat=$(grep -e "$pat" $file | wc -l)
            if [ $nbPat -lt 2 ];
            then time="nbPat time"
            else time="nbPat times"
            fi
            echo "'$pat' found $time in 'file'"
        done