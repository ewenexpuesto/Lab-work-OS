#!/bin/sh
# trie les arguments selon l'algorithme : 
# tant qu'il reste des arguments à traiter faire
# 1 : min -> plus petit des argumennts ; 
# 2 : args -> chaine contenant tous les autres arguments ;
# 3 : écrire min argument sur la sortie standard :
# 4 : mettre à jour la liste des arguments avec set -- $args ; 
# fin

while [ $# -gt 0 ] ; do # tant qu'il reste des arguments à traiter faire
    min="$1"
    args=""
    shift # on retire le premier argument
    for i in "$@" ; do
        if [ "$i" \< "$min" ] ;
        then
            args="$args $min";
            min="$i";
        else
            args="$args $i";
        fi
    done
    # dans $min on a le plus petit argument
    # dans args les autres arguments
    echo -n "$min"
    # on remplace les arguments
    set -- $args
done
echo
            