#!/bin/sh

# usage: s36str a b c => s36str a a b b c c
# usage: s36str k1 s1 k2 s2 k3 s3
# affiche les chaines s(i) en fonction de l'ordre
# des cles k(i). Les cles sont comparees de facon
# lexicographique.
# 21 > 2 ou 00 > 0 par exemple
s36str() {
    if [ $# -eq 3 ] ; then
        s36str "$1" "$1" "$2" "$2" "$3" "$3"
        return 0
    fi
    if [ ! "$1" \> "$3" -a ! "$3" \> "$5" ] ; then # le crochet est un test
        echo $2 ; echo $4 ; echo $6
    elif [ ! "$1" \> "$5" -a ! "$5" \> "$3" ]; then
        echo $2 ; echo $6 ; echo $4
    elif [ ! "$3" \> "$1" -a ! "$1" \> "$5" ]; then
        echo $4 ; echo $2 ; echo $6
    elif [ ! "$3" \> "$5" -a ! "$5" \> "$1" ] ; then
        echo $4 ; echo $6 ; echo $2
    elif [ ! "$5" \> "$1" -a ! "$1" \> "$3" ] ; then
        echo $6 ; echo $2 ; echo $4
    else
        echo $6 ; echo $4 ; echo $2
    fi
}

# il faut faire source à nouveau

# s36int
s36int() {
    if [ $# -eq 3 ] ; then
        s36int "$1" "$1" "$2" "$2" "$3" "$3"
        return 0
    fi
    if [ ! "$1" -gt "$3" -a ! "$3" -gt "$5" ] ; then # -a est and
        echo $2 ; echo $4 ; echo $6
    elif [ ! "$1" -gt "$5" -a ! "$5" -gt "$3" ]; then # en laissant le !, ou mettre -le
        echo $2 ; echo $6 ; echo $4
    elif [ ! "$3" -gt "$1" -a ! "$1" -gt "$5" ]; then
        echo $4 ; echo $2 ; echo $6
    elif [ ! "$3" -gt "$5" -a ! "$5" -gt "$1" ] ; then
        echo $4 ; echo $6 ; echo $2
    elif [ ! "$5" -gt "$1" -a ! "$1" -gt "$3" ] ; then
        echo $6 ; echo $2 ; echo $4
    else
        echo $6 ; echo $4 ; echo $2
    fi
}

# usage: isInt str
# returns 0 if str represents an integer, 1 otherwise
isInt() {
    local n="$1"
    local m=$(echo "$n" | sed -r -e 'ls/[+-]?[0-9]+//') # dans l'ordre : sur la première ligne, éventuellement +- suivi d'une suite de chiffre -> remplacé par rien
    test -z "$m"
}
# + n'est pas vu comme un int car ne contient rien après
# le seul cas où la fonction est fausse est celui où "" est en fait vu comme un int

s3s() {
    if [ $# -ne 3 ] ; then
        echo >&2 "usage: s3s <str1> <str2> <str3>" #ne pas oublier de changer la définition
        # exit 1 # pour sortir du shell
    fi
    s36str "$1" "$1" "$2" "$2" "$3" "$3"
}


s3e() {
    if [ $# -ne 3 ] ; then
        echo >&2 "usage: s3e <int1> <int2> <int3>" #ne pas oublier de changer la définition
        # exit 1 # pour sortir du shell
    fi
    if isInt "$1" -a isInt "$2" -a isInt "$3" ; then # ceci est la bonne syntaxe, éviter les crochets
        echo >&2 "usage: only integers" #ne pas oublier de changer la définition
        # exit 1 # pour sortir du shell
    fi
    s36int "$1" "$2" "$3"
}

s3f() {
    if [ $# -ne 3 ] ; then
        echo >&2 "usage: s3s <file1> <file2> <file3>" #ne pas oublier de changer la définition
        return 0 # erreur donc le programme s'arrête
    fi
    if [ ! "$1" -eq { sed -r -e '~?[/?a-z]' } ] ; then
        echo >&2 "usage : s3f"
        return 0
    fi
    x1=stat "$1" %b
    x2=stat "$1" %B
    x3=stat "$2" %b
    x4=stat "$2" %B
    x5=stat "$3" %b
    x6=stat "$3" %B
    s36int $((x1*x2)) $((x3*x4)) $((x5*x6))
}

# EXERCICE 6

# 1. Écrivez ce script et testez le.

sleepsort() {
    i=1
    k=$#
    while [ $i -lt $(($k+1)) ] ; do
        { sleep "$i" ; echo "$i" ; } &
        i=$((i+1))
    done
}

# Correction
# Ne pas écrire une fonction

#!/bin/sh
for n in "$@" ; do
    { sleep $n ; echo $n ; } &
done
# Attente de n "fils", reflèxe à avoir
for n in "$@" ; do
    wait
done

# 2. Que se passe-t-il si on oublie les { } autour du groupe de commandes ?

# Les accolades lancent un sous-shell qui affiche en parallèle
# Ne trie pas les nombres
# Les accolades ofnt porter l'esperluette sur tout le programme
# Si on enlève les accolades, on affiche lance en parallèle juste le echo

# 3. Quel est son temps d’exécution ?

# 4. À quoi servent les appels à wait ?

# 5. Que peut-on améliorer pour que cela fasse ce que l'on veut ?

