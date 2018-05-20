#!/bin/bash
for (( i=0; i<=1000000000; i+=1000000))
    do
        echo $i":"`/usr/bin/time -f "%e" ./prime_cpp $i 8 > /dev/null`
    done
