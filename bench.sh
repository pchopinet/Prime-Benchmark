#!/bin/bash
for (( i=0; i<=200000000; i+=1000000))
    do
        echo $i":"`/usr/bin/time -f "%e" ./prime_cpp $i 4 > /dev/null`
    done
