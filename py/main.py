import time
from math import sqrt


def est_premier(nombre):
    # print("Test du nombre :", nombre)

    if nombre % 2 == 0:
        return False

    for i in range(3, int(sqrt(nombre)+1), 2):
        if nombre % i == 0:
            return False
    return True


def boucle_nb_premier(start_number, max, pas):
    j = 0
    for i in range(start_number, max, pas):
        if est_premier(i):
            j += 1
    print("Il y a", j, "nombres premier entre", start_number, "et", max)


start_time = time.time()

boucle_nb_premier(1, 100000000, 1)

end_time = time.time()
temps = end_time - start_time
print(temps)
