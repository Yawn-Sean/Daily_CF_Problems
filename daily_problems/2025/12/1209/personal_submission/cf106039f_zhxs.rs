use std::{io::prelude::*, vec};

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
    let m: usize = scanner.next();
    let k: usize = scanner.next();
    let len = n + k;
    let mut edge = vec![vec![]; len + 1];
    for _ in 0..m {
        let u: usize = scanner.next();
        let v: usize = scanner.next();
        let w: usize = scanner.next();
        edge[u].push((v, w));
        edge[v].push((u, w));
    }
    for i in 1..=n {
        let t: usize = scanner.next();
        for _ in 0..t {
            let d: usize = scanner.next();
            let w: usize = scanner.next();
            edge[i].push((n + d, w));
            edge[n + d].push((i, 0));
        }
    }

    let mut dis = vec![usize::MAX; len + 1];
    dis[1] = 0;
    let mut heap = std::collections::BinaryHeap::new();
    heap.push(std::cmp::Reverse((0, 1)));
    while let Some(std::cmp::Reverse((d, u))) = heap.pop() {
        if d > dis[u] {
            continue;
        }
        for &(v, w) in &edge[u] {
            if dis[v] > d + w {
                dis[v] = d + w;
                heap.push(std::cmp::Reverse((dis[v], v)));
            }
        }
    }
    println!("{}", dis[n]);
}
