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

struct DSU {
    parent_or_size: Vec<i32>,
}

impl DSU {
    pub fn new(n: usize) -> Self {
        DSU {
            parent_or_size: vec![-1; n],
        }
    }

    pub fn leader(&mut self, x: usize) -> usize {
        if self.parent_or_size[x] < 0 {
            return x;
        }
        let root = self.leader(self.parent_or_size[x] as usize);
        self.parent_or_size[x] = root as i32;
        root
    }

    pub fn merge(&mut self, mut x: usize, mut y: usize) -> usize {
        x = self.leader(x);
        y = self.leader(y);
        if x == y {
            return x;
        }
        if -self.parent_or_size[x] < -self.parent_or_size[y] {
            std::mem::swap(&mut x, &mut y);
        }
        self.parent_or_size[x] += self.parent_or_size[y];
        self.parent_or_size[y] = x as i32;
        x
    }

    pub fn same(&mut self, x: usize, y: usize) -> bool {
        self.leader(x) == self.leader(y)
    }
}

struct Graph {
    n: usize,
    edge: Vec<Vec<(usize, usize)>>,
}

impl Graph {
    fn new(n: usize) -> Self {
        Graph {
            n,
            edge: vec![vec![]; n],
        }
    }

    fn add(&mut self, u: usize, v: usize, w: usize) {
        self.edge[u].push((v, w));
    }

    fn dijkstra(&self, s: usize) -> Vec<usize> {
        let mut dist = vec![usize::MAX; self.n];
        let mut heap = std::collections::BinaryHeap::new();
        dist[s] = 0;
        heap.push((std::cmp::Reverse(0), s));
        while let Some((std::cmp::Reverse(d), u)) = heap.pop() {
            if d > dist[u] {
                continue;
            }
            for &(v, w) in &self.edge[u] {
                let nd = d + w;
                if nd < dist[v] {
                    dist[v] = nd;
                    heap.push((std::cmp::Reverse(nd), v));
                }
            }
        }
        dist
    }
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let n: usize = scanner.next();
    let m: usize = scanner.next();
    let k: usize = scanner.next();
    let mut edge = Vec::with_capacity(m);
    let mut dsu = DSU::new(n);
    let mut g = Graph::new(n);
    for _ in 0..m {
        let x: usize = scanner.next();
        let y: usize = scanner.next();
        let c: usize = scanner.next();
        dsu.merge(x - 1, y - 1);
        edge.push((x - 1, y - 1, c));
        g.add(x - 1, y - 1, c);
        g.add(y - 1, x - 1, c);
    }

    let mut heap = std::collections::BinaryHeap::new();

    for (x, _, c) in edge {
        if !dsu.same(0, x) {
            continue;
        }

        if heap.len() < k {
            heap.push(c);
        } else if let Some(&top) = heap.peek() {
            if c < top {
                heap.pop();
                heap.push(c);
            }
        }
    }

    let ans = g.dijkstra(0)[n - 1].min(heap.iter().sum());
    println!("{}", ans);
}
