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
        let p: usize = scanner.next();
        let t = 2 * p - 2;
        let len = (t as f64).cbrt().ceil() as usize;
        let mut ans = vec![];

        let check = |b| (p - 1) % (b + 1) == 0 && t % (b + 2) == 0;

        let solve = |m: usize| {
            let s = (4 * m + 1).isqrt();
            if s * s != 4 * m + 1 || s <= 3 || (s - 3) % 2 != 0 {
                return None;
            }
            Some((s - 3) / 2)
        };

        for b in 1..=len {
            if t % (b + 1) == 0 && t % (b + 2) == 0 && check(b) {
                let k = t / (b + 1) / (b + 2);
                if b + 1 >= k {
                    break;
                }
                ans.push(b);
            }
        }

        for k in (1..=len).rev() {
            if t % k == 0 {
                let m = t / k;
                if let Some(b) = solve(m) {
                    if k > b + 1 {
                        break;
                    }
                    if check(b) {
                        ans.push(b);
                    }
                }
            }
        }
        println!("{}", ans.len());
        for b in ans {
            print!("{} ", b);
        }
        println!();
    }
}
