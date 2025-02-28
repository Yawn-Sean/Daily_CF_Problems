//! core logic only
//! submission: https://codeforces.com/problemset/submission/566/293234157
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let mut ans = vec![];
    let mut uf1 = UnionFind::new(n);
    let mut uf2 = UnionFind::new(n);
    for (t, mut x, mut y) in scanner.iter::<(u8, usize, usize)>(q) {
        (x, y) = (x - 1, y - 1);
        match t {
            1 => uf1.union(x, y),
            2 => {
                while uf2.find(x) < y {
                    let p = uf2.find(x);
                    uf1.union(p, p + 1);
                    uf2.union(p, p + 1);
                }
            }
            _ => {
                ans.push(if uf1.find(x) == uf1.find(y) {
                    "YES"
                } else {
                    "NO"
                });
            }
        }
    }
    Sep::<_, '\n'>(ans)
}

struct UnionFind {
    parent: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect(),
        }
    }
    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] == x {
            x
        } else {
            self.parent[x] = self.find(self.parent[x]);
            self.parent[x]
        }
    }
    fn union(&mut self, l: usize, r: usize) {
        let (lp, rp) = (self.find(l), self.find(r));
        if lp != rp {
            self.parent[lp] = rp;
        }
    }
}
