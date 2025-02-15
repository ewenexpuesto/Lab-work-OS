#!/bin/sh
#
#usage

# a. Écrire les arguments un par ligne dans le fichier /tmp/1 ;
for i in "$@" ; do # les " sont importants csiar les arguments peuvent contenir des espaces
    echo "$i"
done | \
# ici les arguments sont dans /tmp/1. Un argument par ligne

# b. Trier le fichier /tmp/1 à l’aide de la commande sort et stocker le résultat dans /tmp/2 ;
sort | \

# c. Écrire le contenu du fichier /tmp/2 sans les sauts de lignes sur le flux de sortie standard.
while read line; do 
    echo -n "$line ";
done

echo