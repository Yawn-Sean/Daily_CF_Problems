use std::{io::prelude::*, isize};

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

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let n: usize = scanner.next();
    let mut h = vec![0; n];
    let mut d = vec![0; n];
    let mut c = vec![0; n];
    for x in &mut h {
        *x = scanner.next();
    }
    for x in &mut d {
        *x = scanner.next();
    }
    for x in &mut c {
        *x = scanner.next();
    }
    let max_h = *h.iter().max().unwrap();
    let mut dp = vec![isize::MIN / 2; max_h + 1];
    dp[0] = 0;
    for i in (0..n).rev() {
        for j in (0..=max_h).rev() {
            let nj = max_h.min(j + d[i]);
            dp[nj] = dp[nj].max(dp[j] - c[i] as isize);
        }
        for j in 0..=max_h {
            dp[j] += j.min(h[i]) as isize;
        }
    }
    let ans = *dp.iter().max().unwrap();
    println!("{}", ans);
}
