//
// Created by pierre on 13/04/19.
//

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int number);

void loop_prime(int start_number, int max, int *j);

void go(const int max);

/*
    argv[1] = limit
*/
int main(int argc, char *argv[]) {

    time_t timeStart = time(0);

    go(atoi(argv[1]));

    time_t timeEnd = time(0);

    float R = (timeEnd - timeStart);
    printf("%f sec\n", R);;

    return 0;
}

bool is_prime(int number) {
    if (number % 2 == 0)
        return false;
    double max = sqrt(number) + 1;
    for (int i = 3; i < max; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void loop_prime(int start_number, int max, int *j) {
    int jj = 0;
#pragma omp parallel for reduction(+:jj)
    for (int i = start_number; i < max; i++) {
        if (is_prime(i)) {
            jj++;
        }
    }
    (*j) += jj;
}

void go(const int max) {
    int j = 0;
    printf("Prime Benchmark : %d\n", max);
    loop_prime(0, max, &j);
    printf("There are %d prime numbers between 1 and %d \n", j, max);
}
