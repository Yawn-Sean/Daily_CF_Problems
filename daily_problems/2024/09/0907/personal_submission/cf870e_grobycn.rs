//! core logic only
//! submission: https://codeforces.com/problemset/submission/870/280329467
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(points: Vec<(i32, i32)>) -> impl Printable {
    use std::collections::HashMap;
    let mut xs = HashMap::new();
    let mut ys = HashMap::new();
    for &(x, y) in &points {
        if !xs.contains_key(&x) {
            let i = xs.len();
            xs.insert(x, i);
        }
        if !ys.contains_key(&y) {
            let i = ys.len();
            ys.insert(y, i);
        }
    }

    let (n, m) = (xs.len(), ys.len());
    let mut uf = UnionFind::new(n + m);
    for (x, y) in &points {
        uf.union(xs[x], n + ys[y]);
    }

    let mut edge_count = vec![0; n + m];
    for (x, y) in &points {
        let p = uf.find(xs[x]);
        edge_count[p] += 1;
    }

    let mut ans = 1;
    for i in 0..n + m {
        let p = uf.find(i);
        if i == p {
            let sz = uf.size[p];
            let cnt = if edge_count[p] >= sz {
                powermod(2, sz, MOD)
            } else {
                (powermod(2, sz, MOD) - 1) % MOD
            };
            ans = (ans * cnt) % MOD;
        }
    }

    ans
}

fn powermod(mut e: usize, mut x: usize, m: usize) -> usize {
    let mut ret = 1;
    while x > 0 {
        if x & 1 != 0 {
            ret = (ret * e) % m;
        }
        e = (e * e) % m;
        x >>= 1;
    }
    ret
}

struct UnionFind {
    parent: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect(),
            size: vec![1; n],
        }
    }
    fn find(&mut self, i: usize) -> usize {
        if i == self.parent[i] {
            return i;
        }
        self.parent[i] = self.find(self.parent[i]);
        self.parent[i]
    }
    fn union(&mut self, i: usize, j: usize) {
        let (mut ip, mut jp) = (self.find(i), self.find(j));
        if ip != jp {
            if self.size[ip] < self.size[jp] {
                std::mem::swap(&mut ip, &mut jp);
            }
            self.size[ip] += self.size[jp];
            self.parent[jp] = ip;
        }
    }
}
