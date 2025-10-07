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

fn solve(a: u32, b: u32) {
    if a & b != b {
        println!("-1");
        return;
    }
    let mut ans = vec![];
    let mut xor_val = b;
    for i in 0..=a {
        if i & a == i {
            ans.push(i);
            xor_val ^= i;
        }
    }
    if xor_val == 0 {
        println!("{}", ans.len());
        for v in ans {
            print!("{} ", v);
        }
        println!();
        return;
    }

    let or_val = ans
        .iter()
        .fold(0, |acc, &x| if x == xor_val { acc } else { acc | x });
    if or_val == a {
        println!("{}", ans.len() - 1);
        for v in ans {
            if v != xor_val {
                print!("{} ", v);
            }
        }
        println!();
    } else {
        println!("-1");
    }
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let t: usize = scanner.next();
    for _ in 0..t {
        let a: u32 = scanner.next();
        let b: u32 = scanner.next();
        solve(a, b);
    }
}
