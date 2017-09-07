#include <QCoreApplication>
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
#include <time.h>
#include <iostream>

bool est_premier(int nombre) {
    if (nombre % 2 == 0)
        return false;

    for (int i = 3; i < sqrt(nombre) + 1; i += 2) {
        if (nombre % i == 0) {
            return false;
        }
    }
    return true;
    }

void boucle_nb_premier(int start_number, int max, int pas) {
    int j = 0;
    for (int i = start_number; i < max; i += pas) {
        if (est_premier(i)) {
            j++;
        }
    }
    printf("There are %d prime numbers between %d and %d \n",j,start_number,max);
}

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    time_t timeStart = time(0);


    boucle_nb_premier(1,100000000,1);
    time_t timeEnd = time(0);

    float R = (timeEnd - timeStart);
    std::cout << R << std::endl;

    return a.exec();
}
