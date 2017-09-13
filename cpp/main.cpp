#include <QCoreApplication>
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
#include <time.h>
#include <iostream>
#include <thread>
#include <vector>

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

void loop_prime(int start_number, int max, int pas,int * j) {
    int jj=0;
    for (int i = start_number; i < max; i += pas) {
        if (is_prime(i)) {
            jj++;
        }
    }
    (*j)+=jj;
}

void go(const int max, const int number_thread){
    int j = 0;
    printf("Prime Benchmark : %d\n", max);
    std::vector<std::thread> tab_t(number_thread);
    int i = 0;
    for(i;i<number_thread;i++){
        tab_t[i] = std::thread(loop_prime,i,max,number_thread,&j);
    }

    for(i=0;i<number_thread;i++){
        tab_t[i].join();
    }
    printf("There are %d prime numbers between 1 and %d \n",j,max);
}




int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    time_t timeStart = time(0);

    go(100000000,8);

    //loop_prime(1,100000000,1);
    time_t timeEnd = time(0);

    float R = (timeEnd - timeStart);
    std::cout << R <<std::string(" sec")<<std::endl;

    return a.exec();
}
