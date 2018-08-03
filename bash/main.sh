#!/bin/bash

is_prime(){
    number=$1
    if [[  $(($number%2)) = 0 ]]; then
        return 0
    fi
    max=$(( $number/2 ))
    for ((i=3 ; $i<$max; i=$i+2))
    do
        if [[  $(($number%$i)) = 0 ]]; then
            return 0
        fi
    done
    return 1
}

loop_prime(){
    start=$1
    max=$2
    pas=$3

    jj=0
    temp=0
    for ((i=$start ; $i<$max; i=$i+$pas))
    do
        $(is_prime $i)
        if [[ $? = 1 ]]; then
            ((jj++))
        fi
    done

    return $jj
}

limit=$1
thread=$2

loop_prime 1 $1 2
nb_prime=$?
echo "There are "$nb_prime" prime numbers between 1 and "$limit
exit $?