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

const P: u64 = 1E9 as u64 + 7;

struct Graph {
    n: usize,
    edge: Vec<Vec<(usize, u64)>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        Graph {
            n,
            edge: vec![vec![]; n],
        }
    }

    fn add(&mut self, u: usize, v: usize, w: u64) {
        self.edge[u].push((v, w));
    }

    fn dijkstra(&self, s: usize) -> (Vec<u64>, Vec<usize>) {
        use std::cmp::Reverse;
        use std::collections::BinaryHeap;

        let mut dis = vec![u64::MAX; self.n];
        let mut heap = BinaryHeap::new();
        dis[s] = 0;
        heap.push(Reverse((0, s)));
        let mut nodes = vec![];

        while let Some(Reverse((d, u))) = heap.pop() {
            if d > dis[u] {
                continue;
            }
            nodes.push(u);
            for &(v, w) in &self.edge[u] {
                let nd = d + w;
                if nd < dis[v] {
                    dis[v] = nd;
                    heap.push(Reverse((nd, v)));
                }
            }
        }

        (dis, nodes)
    }
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let n: usize = scanner.next();
    let m: usize = scanner.next();
    let s: usize = scanner.next();
    let t: usize = scanner.next();
    let l: u64 = scanner.next();
    let mut g = Graph::new(n + 1);
    for _ in 0..m {
        let u: usize = scanner.next();
        let v: usize = scanner.next();
        let w: u64 = scanner.next();
        g.add(u, v, w);
        g.add(v, u, w);
    }

    let (dis, nodes) = g.dijkstra(t);
    let mut dp1 = vec![0; n + 1];
    dp1[s] = 1;

    for &u in nodes.iter().rev() {
        for &(v, w) in &g.edge[u] {
            if dis[v] + w == dis[u] {
                dp1[v] = (dp1[v] + dp1[u]) % P;
            }
        }
    }

    if dis[s] == l {
        println!("{}", dp1[t]);
        return;
    }

    let mut dp2 = vec![0; n + 1];
    dp2[t] = 1;
    for u in nodes {
        for &(v, w) in &g.edge[u] {
            if dis[u] + w == dis[v] {
                dp2[v] = (dp2[v] + dp2[u]) % P;
            }
        }
    }

    let mut ans = 0;
    for u in 1..=n {
        if u != t && dp1[u] > 0 {
            for &(v, w) in &g.edge[u] {
                if dis[s] - dis[u] + w + dis[v] == l {
                    ans = (ans + dp1[u] * dp2[v]) % P;
                }
            }
        }
    }

    println!("{}", ans);
}
