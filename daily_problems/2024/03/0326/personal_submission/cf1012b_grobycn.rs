// core logic only
// submission: https://codeforces.com/problemset/submission/1012/253370685
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let mut uf = UnionFind::new(n + m);
    let mut ans = n + m - 1;

    for (r, c) in scanner.iter::<(usize, usize)>(q) {
        if uf.union(r - 1, n + c - 1) {
            ans -= 1;
        }
    }
    ans
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
    fn find(&mut self, x: usize) -> usize {
        if x == self.parent[x] {
            x
        } else {
            self.parent[x] = self.find(self.parent[x]);
            self.parent[x]
        }
    }
    fn union(&mut self, x: usize, y: usize) -> bool {
        let (mut xp, mut yp) = (self.find(x), self.find(y));
        if xp != yp {
            if self.size[xp] < self.size[yp] {
                std::mem::swap(&mut xp, &mut yp);
            }
            self.parent[yp] = xp;
            self.size[xp] += self.size[yp];
            true
        } else {
            false
        }
    }
}
