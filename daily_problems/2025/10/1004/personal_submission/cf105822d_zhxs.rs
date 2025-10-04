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

    fn bfs(&self, s: usize) -> Vec<usize> {
        let mut dis = vec![usize::MAX; self.n];
        dis[s] = 0;
        let mut queue = std::collections::VecDeque::new();
        queue.push_back(s);
        while let Some(u) = queue.pop_front() {
            for &v in &self.edge[u] {
                if dis[v] == usize::MAX {
                    dis[v] = dis[u] + 1;
                    queue.push_back(v);
                }
            }
        }
        dis
    }
}

fn solve(scanner: &mut Scanner<std::io::StdinLock<'static>>) {
    let n: usize = scanner.next();
    let m: usize = scanner.next();
    let k: usize = scanner.next();
    let mut c = vec![0; k];
    let mut g = Graph::new(n + 1);
    for i in 0..k {
        c[i] = scanner.next();
        if c[i] != 1 {
            let last = if i == 0 { 1 } else { c[i - 1] };
            g.add(last, c[i]);
        }
    }
    for _ in 0..m {
        let u: usize = scanner.next();
        let v: usize = scanner.next();
        g.add(u, v);
        g.add(v, u);
    }

    let dis = g.bfs(1);
    for i in 1..k {
        if dis[c[i]] <= dis[c[i - 1]] {
            println!("-1");
            return;
        }
    }

    let s = if c[0] == 1 { 1 } else { 0 };
    println!("{}", k - s);
    for i in s..k {
        let last = if i == 0 { 1 } else { c[i - 1] };
        println!("{} {}", last, c[i]);
    }
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let t: usize = scanner.next();
    for _ in 0..t {
        solve(&mut scanner);
    }
}
