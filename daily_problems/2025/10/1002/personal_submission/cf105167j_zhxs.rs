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

fn solve(scanner: &mut Scanner<std::io::StdinLock<'static>>) {
    let n: usize = scanner.next();
    let mut a = vec![0; n];
    for i in 0..n {
        a[i] = scanner.next();
    }

    let force_swap = |h, t| {
        let mut b = a.clone();
        let i = b.iter().position(|&v| v == h).unwrap();
        let mut sum = i;
        b[0..=i].rotate_right(1);
        let i = b.iter().position(|&v| v == t).unwrap();
        sum += n - i - 1;
        b[i..n].rotate_left(1);
        (b, sum)
    };

    let f = |h, t| {
        let (mut next_high, mut next_low) = if h == n / 2 + 1 { (2, 1) } else { (1, 2) };
        let (b, mut cnt) = force_swap(h, t);
        for i in 1..n - 1 {
            if b[i] > n / 2 {
                if i > next_high {
                    cnt += i - next_high;
                }
                next_high += 2;
            } else {
                if i > next_low {
                    cnt += i - next_low;
                }
                next_low += 2;
            }
        }
        cnt
    };

    let min_cnt = f(n / 2 + 1, n / 2).min(f(n / 2, n / 2 + 1));
    println!("{} {}", n * n / 2 - 1, min_cnt);
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let t: usize = scanner.next();
    for _ in 0..t {
        solve(&mut scanner);
    }
}
