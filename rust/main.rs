use std::env;
use std::time::Instant;
use std::thread;

fn is_prime(number: u32) -> bool {
    if number % (2 as u32) == 0 {
        return false;
    }

    let max = ((number as f64).sqrt() + 1.0) as u32;
    let mut i: u32 = 3;

    while i < max {
        if number % i == 0 {
            return false;
        }
        i = i + 2;
    }
    return true;
}

fn loop_prime(start_number: u32, max: u32, pas: u32) -> u32 {
    let mut jj: u32 = 0;
    let mut i = start_number;
    while i < max {
        if is_prime(i) {
            jj = jj + 1;
        }
        i = i + pas;
    }
    return jj;
}

fn go(max: u32, number_thread: u32) {
    let mut j: u32 = 0;
    let mut i: u32 = 0;
    println!("Prime benchmark : {}", max);
    let mut threads = Vec::with_capacity(number_thread as usize);

    while i < number_thread * 2 {
        threads.push(thread::spawn(
            move || {
                loop_prime(i + 1, max, number_thread * 2)
            }
        ));
        i = i + 2;
    }

    for thread in threads {
       j = j + thread.join().unwrap();
    }
    println!("There are {} prime numbers between 1 and {}", j, max);
}

fn main() {
    let now = Instant::now();
    let args: Vec<String> = env::args().collect();
    let max: u32 = args[1].parse().unwrap();
    let number_thread: u32 = args[2].parse().unwrap();
    go(max, number_thread);
    println!("{} sec", now.elapsed().as_secs())
}
