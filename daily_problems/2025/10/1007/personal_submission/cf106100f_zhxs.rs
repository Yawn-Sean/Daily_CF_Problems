use std::{collections::{HashMap, VecDeque}, io::prelude::*, vec};

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

pub struct FenwickTree<T> {
    n: usize,
    t: Vec<T>,
}

impl<T> FenwickTree<T>
where
    T: Copy + Default + std::ops::AddAssign + std::ops::Sub<Output = T>,
{
    pub fn new(n: usize) -> Self {
        FenwickTree {
            n,
            t: vec![T::default(); n + 1],
        }
    }

    pub fn add(&mut self, mut i: usize, x: T) {
        i += 1;
        while i <= self.n {
            self.t[i] += x;
            i += Self::lowbit(i);
        }
    }

    pub fn range_sum(&self, l: usize, r: usize) -> T {
        self.prefix(r) - self.prefix(l)
    }

    fn lowbit(x: usize) -> usize {
        x & (!x + 1)
    }

    fn prefix(&self, mut i: usize) -> T {
        let mut res = T::default();
        while i > 0 {
            res += self.t[i];
            i -= Self::lowbit(i);
        }
        res
    }
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let n = scanner.next();
    let mut a = vec![0; n];
    for i in 0..n {
        a[i] = scanner.next();
        a[i] -= i as u32;
    }
    let mut pos = HashMap::<u32, VecDeque<usize>>::new();
    for (i, x) in a.into_iter().enumerate() {
        pos.entry(x).or_default().push_back(i);
    }

    let mut b = vec![0; n];
    for i in 0..n {
        b[i] = scanner.next();
        b[i] -= i as u32;
    }

    let mut t = FenwickTree::<i64>::new(n);
    let mut ans = 0;
    for x in b {
        if let Some(q) = pos.get_mut(&x) {
            if let Some(rk) = q.pop_front() {
                ans += t.range_sum(rk + 1, n);
                t.add(rk, 1);
            } else {
                ans = -1;
                break;
            }
        } else {
            ans = -1;
            break;
        }
    }
    println!("{}", ans);
}
