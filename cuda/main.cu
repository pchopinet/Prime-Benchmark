#include <stdio.h>
#include <time.h>
#include <stdlib.h>

__device__ bool is_prime(int number);

__global__ void loop_prime(int max, int pas, int *j);

void go(const int max, const int number_block);

/*
    argv[1] = limit
    argv[2] = Number of block
*/
int main(int argc, char *argv[]) {

    time_t timeStart = time(0);

    go(atoi(argv[1]), atoi(argv[2]));

    time_t timeEnd = time(0);

    float R = (timeEnd - timeStart);
    printf("%f sec\n", R);;

    return 0;
}

__device__
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

__global__
void loop_prime(int max, int pas, int *j) {
    int index = threadIdx.x + blockIdx.x * blockDim.x;;
    int i = index;
    if (i % 2 == 0) {
        i += pas + 1;
    }
    //printf("%d ",i);
    for (; i < max; i += pas * 2) {
        if (is_prime(i)) {
            j[index]++;
        }
    }
    //printf("%d ",j[index]);
}

void go(const int max, const int number_block) {
    int nbBlock = number_block;
    int nbThread = 64;
    int nb = nbBlock * nbThread;
    int j = 0;

    printf("Prime Benchmark : %d\n", max);

    int ha[nb];
    int *da;

    cudaMalloc((void **) &da, nb * sizeof(int));

    for (int i = 0; i < nb; ++i) {
        ha[i] = 0;
    }

    cudaMemcpy(da, ha, nb * sizeof(int), cudaMemcpyHostToDevice);

    loop_prime <<< nbBlock, nbThread >>> (max, nb, da);

    cudaMemcpy(ha, da, nb * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < nb; ++i) {
        j += ha[i];
    }

    cudaFree(da);

    printf("\nThere are %d prime numbers between 1 and %d \n", j, max);
}
