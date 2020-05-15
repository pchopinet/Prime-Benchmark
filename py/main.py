import multiprocessing as mp
import time

from py.prime import *


def loop_prime(start_number, max, pas, q):
    jj = 0
    for i in range(start_number, max, pas):
        if is_prime(i):
            jj += 1
            #print(start_number, i)
    print(start_number, jj)
    q.put(jj)


def go(max_value, number_thread):
    j = 0
    print("Prime Benchmark :", max_value)

    tab_t = []
    q = mp.Queue()
    for i in range(0, number_thread * 2, 2):
        k = i + 1
        t = mp.Process(target=loop_prime, args=(k, max_value, number_thread * 2, q))
        tab_t.append(t)

    for t in tab_t:
        t.start()

    for t in tab_t:
        t.join()

    while not q.empty():
        j += q.get()

    print("There are", j, "prime numbers between", 1, "and", max_value)


def __main__():
    if __name__ == '__main__':
        start_time = time.time()

        go(100_000_000, 16)

        end_time = time.time()
        time_exec = end_time - start_time
        print(time_exec)


__main__()
