import time
from math import sqrt


def is_prime(nombre):
    # print("Test du nombre :", nombre)

    if nombre % 2 == 0:
        return False

    for i in range(3, int(sqrt(nombre)+1), 2):
        if nombre % i == 0:
            return False
    return True


def loop_prime(start_number, max, pas):
    j = 0
    for i in range(start_number, max, pas):
        if is_prime(i):
            j += 1
    print("There are", j, "prime numbers between", start_number, "and", max)


start_time = time.time()

loop_prime(1, 100000000, 1)

end_time = time.time()
temps = end_time - start_time
print(temps)
