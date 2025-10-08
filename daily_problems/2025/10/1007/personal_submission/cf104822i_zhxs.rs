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

fn pre_cal() -> Vec<usize> {
    const MAXA: usize = 1E9 as usize;
    const N: usize = MAXA.isqrt();
    let mut isp = vec![true; N + 1];
    let mut prime = vec![];
    for i in 2..=N {
        if isp[i] {
            prime.push(i);
        }
        for p in &prime {
            if i * p > N {
                break;
            }
            isp[i * p] = false;
            if i % p == 0 {
                break;
            }
        }
    }
    prime
}

fn dfs(i: usize, mut prod: usize, ans: &mut usize, cnt: &Vec<(usize, usize)>, a: usize) {
    if i == cnt.len() {
        if prod > a {
            *ans = (*ans).min(prod);
        }
        return;
    }
    let (p, c) = cnt[i];
    for _ in 0..=c {
        if prod > *ans {
            break;
        }
        dfs(i + 1, prod, ans, cnt, a);
        prod *= p;
    }
}

fn solve(a: usize, prime: &Vec<usize>) {
    let mut cnt = vec![];
    let mut n = a;
    for &p in prime {
        if p * p > n {
            break;
        }
        if n % p == 0 {
            let mut c = 0;
            while n % p == 0 {
                n /= p;
                c += 1;
            }
            cnt.push((p, 2 * c));
        }
    }
    if n > 1 {
        cnt.push((n, 2));
    }
    let mut ans = usize::MAX;
    dfs(0, 1, &mut ans, &cnt, a);
    println!("{}", ans - a);
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let prime = pre_cal();
    let t: usize = scanner.next();
    for _ in 0..t {
        let a: usize = scanner.next();
        solve(a, &prime);
    }
}
