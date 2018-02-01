#include <stdio.h>
#include <time.h>

using namespace std;

__device__ bool is_prime(int number);
__global__ void loop_prime(int max,int pas, int * j);
void go(const int max, const int number_thread);

/*
    argv[1] = limit
    argv[2] = Thread number
*/
int main(int argc, char *argv[]) {

    //QCoreApplication a(argc, argv);
    time_t timeStart = time(0);

    go(atoi(argv[1]),atoi(argv[2]));

    time_t timeEnd = time(0);

    float R = (timeEnd - timeStart);
    printf("%f sec\n",R);;

    //return a.exec();
    return 0;
}
__device__
bool is_prime(int number) {
    if (number % 2 == 0)
        return false;
    double max = number/2;
    for (int i = 3; i < max; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}
__global__
void loop_prime(int max,int pas,int * j) {
    int jj=0;
    for (int i = blockIdx.x; i < max; i += pas) {
        if (is_prime(i)) {
            jj++;
        }
    }
    (*j)+=jj;
}

void go(const int max, const int number_thread) {
    int j = 0;
    int ha[number_thread];

    printf("Prime Benchmark : %d\n", max);

    int *da;
    cudaMalloc((void **)&da, number_thread*sizeof(int));

    for (int i = 0; i<number_thread; ++i) {
        ha[i] = 0;
    }

    cudaMemcpy(da, ha, number_thread*sizeof(int), cudaMemcpyHostToDevice);

    loop_prime<<<number_thread, 1>>>(max,number_thread,da);

    cudaMemcpy(ha, da, number_thread*sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i<number_thread; ++i) {
        j+=ha[i];
    }

    cudaFree(da);

    printf("There are %d prime numbers between 1 and %d \n",j,max);
}
