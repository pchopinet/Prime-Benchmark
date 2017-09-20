import time
from math import sqrt
from threading import Thread
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
    q = queue.Queue()
    for i in range(0, number_thread * 2, 2):
        k = i + 1
        t = Thread(target=loop_prime, args=(k, max, number_thread * 2, q))
        t.start()
        tab_t.append(t)

    for i in range(number_thread):
        tab_t[i].join()

    while not q.empty():
        j += q.get()

    print("There are", j, "prime numbers between", 1, "and", max)


start_time = time.time()

go(100000000, 8)

end_time = time.time()
time_exec = end_time - start_time
print(time_exec)
