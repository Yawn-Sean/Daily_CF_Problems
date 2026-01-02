use std::{collections::HashMap, io::prelude::*};

pub struct Scanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: std::str::SplitAsciiWhitespace<'static>,
}

impl<R: BufRead> Scanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: Vec::new(),
            buf_iter: "".split_ascii_whitespace(),
        }
    }
    pub fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = std::str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            }
        }
    }
}

const MAXX: usize = 2E5 as usize;

fn get_prime(n: usize) -> Vec<usize> {
    let mut isp = vec![true; n + 1];
    let mut primes = Vec::new();
    for i in 2..=n {
        if isp[i] {
            primes.push(i);
        }
        for &p in &primes {
            if i * p > n {
                break;
            }
            isp[i * p] = false;
            if i % p == 0 {
                break;
            }
        }
    }
    primes
}

fn solve(scanner: &mut Scanner<std::io::StdinLock<'static>>, primes: &Vec<usize>) {
    let mut x: usize = scanner.next();
    let mut k: isize = scanner.next();
    let mut cnt = HashMap::<isize, i32>::new();

    for &p in primes {
        if p * p > x {
            break;
        }
        if x % p == 0 {
            let mut c = 0;
            while x % p == 0 {
                x /= p;
                c += 1;
            }
            *cnt.entry(c).or_insert(0) += 1;
        }
    }
    if x > 1 {
        *cnt.entry(1).or_insert(0) += 1;
    }

    for x in 1.. {
        let mut next_cnt = HashMap::new();
        let bit = 1isize << x;
        for (&c, &cnt) in &cnt {
            let r = c % bit;
            if r != 0 {
                let d = bit - r;
                if k < d * cnt as isize {
                    println!("{}", x - 1);
                    return;
                }
                k -= d * cnt as isize;
                let nc = c + d;
                *next_cnt.entry(nc).or_insert(0) += cnt;
            } else {
                *next_cnt.entry(c).or_insert(0) += cnt;
            }
        }
        cnt = next_cnt;
    }
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let primes = get_prime((MAXX as f64).sqrt() as usize);
    let t: usize = scanner.next();
    for _ in 0..t {
        solve(&mut scanner, &primes);
    }
}
