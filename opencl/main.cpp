//
// Created by pierre on 20/05/18.
//
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <thread>
#include <vector>
#include <CL/cl.h>


bool is_prime(int number);

__kernel void loop_prime(int max, int pas, __global int *j);

void go(const int max, const int number_block);

int main() {

}

bool is_prime(int number) {
    if (number % 2 == 0)
        return false;
    float max = sqrtf(number) + 1;
    for (int i = 3; i < max; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

__kernel void loop_prime(int max, int pas, __global int *j) {

}

void go(const int max, const int number_block) {

}


