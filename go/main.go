package main

import (
	"fmt"
	"math"
	"sync"
	"time"
)

var wg sync.WaitGroup

func is_prime(number int) bool {
	if number%2 == 0 {
		return false
	}
	max := int(math.Sqrt(float64(number)))+1
	for i := 3; i < max ; i++ {
		if number%i == 0 {
			return false
		}
	}
	return true
}

func loop_prime(start_number, max, pas int, j *int) {
	defer wg.Done()
	var jj int
	for i := start_number; i < max; i += pas {
		if is_prime(i) {
			jj++
		}
	}
	fmt.Println(jj)
	*j += jj
}

func launch(max, number_thread int) {
	var j int
	fmt.Println("Prime Benchmark : ", max)
	wg.Add(number_thread)
	for i := 0; i < number_thread*2; i+=2 {
		k := i+1
		go loop_prime(k, max, number_thread*2, &j)
	}
	wg.Wait()

	fmt.Println("There are", j, "prime numbers between", 1, "and", max);
}

func main() {
	start := time.Now()
	launch(100000000, 8)
	t := time.Now()
	elapsed := t.Sub(start)
	fmt.Println(elapsed, "sec")
}
