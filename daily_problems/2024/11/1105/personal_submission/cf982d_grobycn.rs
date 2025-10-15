//! core logic only
//! submission: https://codeforces.com/problemset/submission/982/290105300
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<usize>) -> impl Printable {
    let n = a.len();
    let mut uf = UnionFind::new(n);
    let mut indice: Vec<_> = (0..n).collect();
    indice.sort_unstable_by_key(|&i| a[i]);

    let mut vis = vec![false; n];
    let mut count = vec![0; n + 1];
    let (mut nloc, mut ans) = (0, usize::MAX);
    for (&i, tot) in indice.iter().zip(1..) {
        if i > 0 && vis[i - 1] {
            let p = uf.find(i - 1);
            let sz = uf.size[p];
            count[sz] -= 1;
            uf.union(p, i);
        }
        if i + 1 < n && vis[i + 1] {
            let p = uf.find(i + 1);
            let sz = uf.size[p];
            count[sz] -= 1;
            uf.union(i, p);
        }
        let p = uf.find(i);
        let sz = uf.size[p];
        count[sz] += 1;
        if count[sz] * sz == tot {
            if count[sz] > nloc {
                nloc = count[sz];
                ans = a[i] + 1;
            }
        }
        vis[i] = true;
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
    fn union(&mut self, x: usize, y: usize) {
        let (mut xp, mut yp) = (self.find(x), self.find(y));
        if xp == yp {
            return;
        }
        if self.size[xp] < self.size[yp] {
            std::mem::swap(&mut xp, &mut yp);
        }
        self.size[xp] += self.size[yp];
        self.parent[yp] = self.parent[xp];
    }
}
