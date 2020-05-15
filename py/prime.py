from math import sqrt


def is_prime(nombre):
    if nombre % 2 == 0:
        return False
    max = int(sqrt(nombre) + 1)
    for i in range(3, max, 2):
        if nombre % i == 0:
            return False
    return True
