use std::{
    collections::{HashMap},
    io::prelude::*,
    usize,
};

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

fn gcd(a: u32, b: u32) -> u32 {
    if b == 0 { a } else { gcd(b, a % b) }
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

    fn solve(&self, a: &mut Vec<u32>) -> bool {
        let s = self.find_middle();
        let mut mp = HashMap::new();
        for &v in &self.edge[s] {
            let mut mp_v = HashMap::new();
            self.get_map(v, s, gcd(a[s], a[v]), 1, a, &mut mp_v);
            for (g, dep) in mp_v {
                if g == 1 {
                    continue;
                }
                let c = mp.get(&g).unwrap_or(&0);
                if (dep + c + 1) as usize > self.n / 2 {
                    return true;
                }
                mp.entry(g)
                    .and_modify(|v| *v = (*v).max(dep))
                    .or_insert(dep);
            }
        }
        false
    }

    fn find_middle(&self) -> usize {
        let mut pre = vec![0; self.n];
        let (_, s) = self.dfs(0, self.n, &mut pre);
        let (d, mut t) = self.dfs(s, self.n, &mut pre);
        for _ in 0..d / 2 {
            t = pre[t];
        }
        t
    }

    fn dfs(&self, u: usize, fa: usize, pre: &mut Vec<usize>) -> (u32, usize) {
        pre[u] = fa;
        let mut ans = (0, u);
        for &v in &self.edge[u] {
            if v == fa {
                continue;
            }
            ans = ans.max(self.dfs(v, u, pre));
        }
        ans.0 += 1;
        ans
    }

    fn get_map(
        &self,
        u: usize,
        fa: usize,
        g: u32,
        dep: u32,
        a: &mut Vec<u32>,
        mp: &mut HashMap<u32, u32>,
    ) {
        mp.entry(g)
            .and_modify(|v| *v = (*v).max(dep))
            .or_insert(dep);
        for &v in &self.edge[u] {
            if v == fa {
                continue;
            }
            self.get_map(v, u, gcd(g, a[v]), dep + 1, a, mp);
        }
    }
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let n: usize = scanner.next();
    let mut a = vec![0; n];
    for i in 0..n {
        a[i] = scanner.next();
    }
    let mut g = Graph::new(n);
    for _ in 0..n - 1 {
        let u: usize = scanner.next();
        let v: usize = scanner.next();
        g.add(u - 1, v - 1);
        g.add(v - 1, u - 1);
    }
    if g.solve(&mut a) {
        println!("YES");
    } else {
        println!("NO");
    }
}
