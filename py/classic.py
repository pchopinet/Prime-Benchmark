import time

from py.prime import is_prime


def loop_prime(start_number, max, pas):
    jj = 0

    for i in range(start_number, max, pas):
        if is_prime(i):
            jj += 1
    print(jj)
    return jj


def go(max_value):
    print("Prime Benchmark :", max_value)

    j = loop_prime(1, max_value, 2)

    print("There are", j, "prime numbers between", 1, "and", max_value)


def __main__():
    if __name__ == '__main__':
        start_time = time.time()

        go(100_000_000)

        end_time = time.time()
        time_exec = end_time - start_time
        print(time_exec)


__main__()
