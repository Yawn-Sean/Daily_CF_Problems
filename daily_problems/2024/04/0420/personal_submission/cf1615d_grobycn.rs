// core logic only
// submission: https://codeforces.com/problemset/submission/1615/257423751
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut uf = UnionFind::new(2 * n);
    let mut edges: Vec<(usize, usize, i32)> = scanner.iter(n - 1).collect();
    for (mut x, mut y, v) in edges.iter().copied().chain(scanner.iter(m)) {
        if v == -1 {
            continue;
        }
        (x, y) = (x - 1, y - 1);
        let p = v.count_ones() & 1;
        if p == 0 {
            if uf.find(x) == uf.find(y + n) {
                return Err("NO");
            }
            uf.union(x, y);
            uf.union(x + n, y + n);
        } else {
            if uf.find(x) == uf.find(y) {
                return Err("NO");
            }
            uf.union(x, y + n);
            uf.union(x + n, y);
        }
    }

    for (x, y, v) in edges.iter_mut() {
        if *v == -1 {
            let (x, y) = (*x - 1, *y - 1);
            if uf.find(x) == uf.find(y) {
                *v = 0;
            } else {
                *v = 1;
                uf.union(x, y + n);
                uf.union(x + n, y);
            }
        }
    }

    Ok("YES".cr().then(Sep::<_, '\n'>(edges)))
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
    fn find(&mut self, mut x: usize) -> usize {
        if x == self.parent[x] {
            x
        } else {
            self.parent[x] = self.find(self.parent[x]);
            self.parent[x]
        }
    }
    fn union(&mut self, x: usize, y: usize) {
        let (mut xp, mut yp) = (self.find(x), self.find(y));
        if xp != yp {
            if self.size[xp] < self.size[yp] {
                std::mem::swap(&mut xp, &mut yp);
            }
            self.size[xp] += self.size[yp];
            self.parent[yp] = xp;
        }
    }
}
