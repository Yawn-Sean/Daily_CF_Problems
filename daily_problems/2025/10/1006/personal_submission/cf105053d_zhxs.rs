use std::{collections::HashMap, io::prelude::*};

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
    let mut n: usize = scanner.next();
    if n == 1 {
        println!("N");
        return;
    }
    let mut cnt = HashMap::new();
    let mut sum = 1;
    let mut i = 2;
    loop {
        if i * i > n {
            break;
        }
        if n % i == 0 {
            let mut c = 0;
            while n % i == 0 {
                n /= i;
                c += 1;
            }
            sum *= c + 1;
            cnt.insert(i, c);
        }
        i += 1;
    }
    if n > 1 {
        cnt.insert(n, 1);
        sum *= 2;
    }

    if sum % 2 == 1 {
        println!("N");
        return;
    }

    if cnt.len() == 1 {
        println!("Y");
        return;
    }

    if cnt.len() == 2 {
        if sum == 4 {
            println!("Y");
        } else {
            println!("N");
        }
    } else {
        println!("N");
    }
}
