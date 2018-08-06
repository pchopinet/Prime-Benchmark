//
// Created by pierre on 04/08/18.
//

#include <stdio.h>
#include <math.h>
#include <time.h>
#include "TCPserver.h"
#include "TCPutil.h"

int is_prime(int number);

int loop_prime(int start_number, int max, int pas);

int is_prime(int number) {
    if (number % 2 == 0)
        return 0;
    double max = sqrt(number) + 1;
    for (int i = 3; i < max; i += 2) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int loop_prime(int start_number, int max, int pas) {
    int jj = 0;
    for (int i = start_number; i < max; i += pas) {
        if (is_prime(i)) {
            jj++;
        }
    }
    return jj;
}

void *go(void *socket) {
    time_t timeStart = time(0);

    int *socketClient = (int *) socket;
    char *c = TCPrecv(*socketClient);
    printf("Recv : %s\n", c);
    int start = atoi(strtok(c, " "));
    int max = atoi(strtok(NULL, " "));
    int step = atoi(strtok(NULL, " "));
    printf("start : %d nmax : %d step : %d\n", start, max, step);
    printf("Prime Benchmark : %d\n", max);
    int j = loop_prime(start, max, step);
    printf("%d\n", j);

    char temp[255];
    sprintf(temp, "%d", j);
    TCPsend(*socketClient, temp);

    time_t timeEnd = time(0);
    float R = (timeEnd - timeStart);
    printf("%f sec\n", R);

    close(*socketClient);
    free(socketClient);
}

int main(int argc, char *argv[]) {
    TCPserver(atoi(argv[1]), go);
    return 0;
}