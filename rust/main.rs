use std::env;
use std::time::Instant;

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
    //let mut i: u32 = 0;
    println!("Prime benchmark : {}", max);
    j = j + loop_prime(1, max, 2);

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
