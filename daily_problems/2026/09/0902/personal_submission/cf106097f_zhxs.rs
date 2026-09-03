use std::io::{prelude::*, stdout};

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
    let n: i32 = scanner.next();

    let mut guess = |mut l, mut r| -> Option<i32> {
        while l <= r {
            let mid = (l + r) / 2;
            println!("{}", mid);
            stdout().flush().unwrap();
            let ds: String = scanner.next();
            let d = ds.as_bytes()[0];
            if d == b'=' {
                return Some(mid);
            }
            if d == b'<' {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        };
        None
    };

    let x1 = guess(1, n).unwrap();
    if let Some(x2) = guess(1, x1 - 1) {
        println!("! {} {}", x2, x1);
    } else if let Some(x2) = guess(x1 + 1, n) {
        println!("! {} {}", x1, x2);
    } else {
        unreachable!();
    }
    stdout().flush().unwrap();
}
