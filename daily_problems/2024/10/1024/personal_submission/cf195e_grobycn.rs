//! core logic only
//! submission: https://codeforces.com/problemset/submission/195/287677582
const MULTIPLE_TEST: bool = false;
const MOD: i64 = 1_000_000_007;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut uf = UnionFind::new(n);
    let mut ans = 0;
    for i in 0..n {
        let k = usize::from_scanner(scanner);
        for (v, x) in scanner.iter::<(usize, i64)>(k) {
            ans = (ans + uf.union(v - 1, i, x)) % MOD;
        }
    }
    ans
}

struct UnionFind {
    parent: Vec<usize>,
    depth: Vec<i64>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect(),
            depth: vec![0; n],
        }
    }
    fn find(&mut self, i: usize) -> (usize, i64) {
        if i == self.parent[i] {
            (i, 0)
        } else {
            let (p, d) = self.find(self.parent[i]);
            self.parent[i] = p;
            self.depth[i] = (self.depth[i] + d) % MOD;
            (self.parent[i], self.depth[i])
        }
    }
    fn union(&mut self, x: usize, p: usize, mut d: i64) -> i64 {
        let (xp, xd) = self.find(x);
        self.parent[xp] = p;
        d = (d + MOD + xd) % MOD;
        self.depth[xp] = d;
        d
    }
}
