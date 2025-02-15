#!/bin/sh
# Usage : 

# QUESTION 1

if [ $# -eq 1 ] ; then
    dir="$1"
    withSum=0 # Si on a vu ou pas l'option -s
elif [ $# -eq 2 -a "$1"="-s" ] ; then
    dir="$2"
    withSum=1
else
    echo "usage <nauuuur>"
fi

# On peut faire for ... in ls, mais le nombre de fichiers est trop grand
#for fich in $(find $dir -name '*'); do # Parcourt toutes les adresses des fichiers du répertoire
#    if [ ! $fich -eq { sed -r -e '/dir[/?a-z]' } ] ; then
#            echo stat -c '%u' $fich
#    fi

# Correction
# Utilisateur pour chaque fichier de dir
find $dir -type f -exec stat -c "%U" {} \; 2> /dev/null | sort -u | \
    while read user; do
        echo -n "$user ";
        if [ $withSum -eq 0 ]
        then
            find $dir -type f -user "$user" | wc -l
        else
            echo "question 1 only"
        fi
    done
# Faire en sorte d'échapper en cas d'erreur de permission non accordée (2> /dev/null)