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

const P: usize = 998244353;

fn qpow(mut a: usize, mut x: usize) -> usize {
    let mut res = 1;
    while x > 0 {
        if x & 1 == 1 {
            res = res * a % P;
        }
        a = a * a % P;
        x >>= 1;
    }
    res
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let n: usize = scanner.next();
    let k: usize = scanner.next();
    let mut a = vec![0; n];
    let mut b = vec![0; n];
    for i in 0..n {
        a[i] = scanner.next();
    }
    for i in 0..n {
        b[i] = scanner.next();
    }
    let t = a
        .iter()
        .zip(b.iter())
        .fold(0, |acc, (&ai, &bi)| (acc + ai * bi) % P);
    let c = qpow(t, k - 1);
    let a_sum = a.iter().fold(0, |acc, &ai| (acc + ai) % P);
    let b_sum = b.iter().fold(0, |acc, &bi| (acc + bi) % P);
    let ans = c * a_sum % P * b_sum % P;
    println!("{}", ans);
}
