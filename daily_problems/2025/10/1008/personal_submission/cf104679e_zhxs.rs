use std::io::prelude::*;

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

const MAXN: usize = 1E7 as usize;

fn get_prime(n: usize) -> Vec<i8> {
    let mut isp = vec![1; n + 1];
    let mut primes = Vec::new();
    for i in 2..=n {
        if isp[i] == 1 {
            primes.push(i);
        }
        for &p in &primes {
            if i * p > n {
                break;
            }
            isp[i * p] = 0;
            if i % p == 0 {
                break;
            }
        }
    }

    isp
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let mut isp = get_prime(MAXN);
    for i in 3..=MAXN / 2 {
        if isp[i] == 1 {
            isp[i * 2] = -1;
        }
    }
    let mut sum = 1;
    let mut f = vec![0; MAXN + 1];
    for i in 3..=MAXN {
        sum += isp[i] as i32;
        f[i] = sum - 1;
    }

    let t: usize = scanner.next();
    for _ in 0..t {
        let n: usize = scanner.next();
        println!("{}", f[n]);
    }
}
