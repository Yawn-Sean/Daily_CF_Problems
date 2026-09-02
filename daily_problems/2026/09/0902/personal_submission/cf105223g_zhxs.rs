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

const MAXB: usize = 30;
const MOD: i64 = 1E9 as i64 + 7;
const REV2: i64 = (MOD + 1) / 2;

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let n: usize = scanner.next();
    let mut a = vec![0; n];
    let mut cnt = [0; MAXB];
    for i in 0..n {
        a[i] = scanner.next();
        for j in 0..MAXB {
            if (a[i] >> j) & 1 == 1 {
                cnt[j] += 1;
            }
        }
    }
    let mut pow3 = vec![1i64; n + 1];
    for i in 1..=n {
        pow3[i] = (pow3[i - 1] * 3) % MOD;
    }
    let q: usize = scanner.next();
    for _ in 0..q {
        let i: usize = scanner.next();
        let i = i - 1;
        let x: i32 = scanner.next();
        for j in 0..MAXB {
            if (a[i] >> j) & 1 == 1 {
                cnt[j] -= 1;
            }
            if (x >> j) & 1 == 1 {
                cnt[j] += 1;
            }
        }
        a[i] = x;
        let mut ans = 0;
        for j in (0..MAXB).rev() {
            ans = 2 * ans % MOD;
            let v = (pow3[n] - pow3[n - cnt[j]] + MOD) % MOD;
            ans = (ans + v) % MOD;
        }
        ans = (ans * REV2) % MOD;
        println!("{}", ans);
    }
}
