use std::{io::prelude::*, usize};

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

fn f(x: usize, y: usize) -> usize {
    x.max(y) + x.min(y).isqrt()
}

struct Graph {
    n: usize,
    edge: Vec<Vec<usize>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        Graph {
            n,
            edge: vec![vec![]; n],
        }
    }

    fn add(&mut self, u: usize, v: usize) {
        self.edge[u].push(v);
    }

    fn dfs1(
        &self,
        u: usize,
        fa: usize,
        best: &mut Vec<[(usize, usize); 2]>,
        a: &Vec<usize>,
    ) -> usize {
        best[u][0] = (a[u], self.n);
        for &v in &self.edge[u] {
            if v == fa {
                continue;
            }
            let max_v = self.dfs1(v, u, best, a);
            let t = f(max_v, a[u]);
            if t > best[u][0].0 {
                best[u][1] = best[u][0];
                best[u][0] = (t, v);
            } else if t > best[u][1].0 {
                best[u][1] = (t, v);
            }
        }
        best[u][0].0
    }

    fn dfs2(
        &self,
        u: usize,
        fa: usize,
        prefix: usize,
        best: &Vec<[(usize, usize); 2]>,
        a: &Vec<usize>,
    ) -> usize {
        let prefix = f(prefix, a[u]);
        let mut ans = prefix;
        for &v in &self.edge[u] {
            if v == fa {
                continue;
            }
            if v == best[u][0].1 {
                ans = ans.max(self.dfs2(v, u, prefix.max(best[u][1].0), best, a));
            } else {
                ans = ans.max(self.dfs2(v, u, prefix.max(best[u][0].0), best, a));
            }
        }
        ans
    }
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let n: usize = scanner.next();
    let mut g = Graph::new(n);
    let mut a = vec![0; n];
    for x in &mut a {
        *x = scanner.next();
    }
    for _ in 1..n {
        let u: usize = scanner.next();
        let v: usize = scanner.next();
        g.add(u - 1, v - 1);
        g.add(v - 1, u - 1);
    }
    let mut best = vec![[(0, n); 2]; n];
    let mut ans = g.dfs1(0, n, &mut best, &a);
    ans = ans.max(g.dfs2(0, n, 0, &best, &a));
    println!("{}", ans);
}
