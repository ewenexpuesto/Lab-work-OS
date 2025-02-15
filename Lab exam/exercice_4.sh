FILE=/home/ewen.expuesto/OSSE_2024_TPN/exo4_data.txt
export FILE

if [ "$#" -eq 1 -a "$0" = --list-products ]
    then
    for line in $( cat FILE ) 
    do
        grep "product*" line
    done
fi

if [ "$#" -eq 1 -a "$0" = --list-products -a "$1" = --list ]
    then
    for line in $( cat FILE ) 
    do
        grep "$1" line
    done
fi
