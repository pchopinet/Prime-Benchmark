import time
from math import sqrt
import multiprocessing as mp
import queue


def is_prime(nombre):
    if nombre % 2 == 0:
        return False
    max = int(sqrt(nombre) + 1)
    for i in range(3, max, 2):
        if nombre % i == 0:
            return False
    return True


def loop_prime(start_number, max, pas, q):
    jj = 0
    for i in range(start_number, max, pas):
        if is_prime(i):
            jj += 1
    print(jj)
    q.put(jj)


def go(max, number_thread):
    j = 0
    print("Prime Benchmark :", max)

    tab_t = []
    q = mp.Queue()
    for i in range(0, number_thread * 2, 2):
        k = i + 1
        t = mp.Process(target=loop_prime, args=(k, max, number_thread * 2, q))
        tab_t.append(t)

    for t in tab_t:
        t.start()

    for t in tab_t:
        t.join()

    while not q.empty():
        j += q.get()

    print("There are", j, "prime numbers between", 1, "and", max)


def __main__():
    if __name__ == '__main__':
        start_time = time.time()

        go(10000000, 4)

        end_time = time.time()
        time_exec = end_time - start_time
        print(time_exec)

__main__()