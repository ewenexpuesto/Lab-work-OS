#!bin/bash

if [ "$#" = 0 ] 
then
    echo "usage: exercice_3.sh <file> [<file> ...]" ;
    exit 1
else
    find / -type d > /tmp/list.txt
    for repo1 in "$@ "
    do
        for repo2 in /tmp/list.txt
        do
            if [ ! repo1 != repo2 ] 
            then
                echo "$(repo1) not found"
            fi
        done
    done
fi




