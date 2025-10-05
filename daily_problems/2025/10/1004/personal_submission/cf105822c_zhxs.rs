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

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let t: usize = scanner.next();
    for _ in 0..t {
        let n: usize = scanner.next();
        let s: String = scanner.next();
        let s = s.as_bytes();
        let mut cnt_odd = 0;
        for &ch in s {
            if ch == b'O' {
                cnt_odd += 1;
            }
        }
        if cnt_odd > n || (n - cnt_odd) % 2 != 0 {
            println!("NO");
            continue;
        }
        println!("YES");
        let mut next_odd = 1;
        let mut next_even = 2;
        for &ch in s {
            if ch == b'O' {
                let mut x = next_odd;
                let mut y = next_even;
                if x > y {
                    std::mem::swap(&mut x, &mut y);
                }
                println!("{} {}", x, y);
                next_odd += 2;
                next_even += 2;
                cnt_odd -= 1;
            } else {
                let k = (2 * n + 1 - next_odd) / 2;
                if k < cnt_odd + 2 || 2 * next_even + 2 <= 2 * next_odd + 2 {
                    println!("{} {}", next_even, next_even + 2);
                    next_even += 4;
                } else {
                    println!("{} {}", next_odd, next_odd + 2);
                    next_odd += 4;
                }
            }
        }
    }
}
