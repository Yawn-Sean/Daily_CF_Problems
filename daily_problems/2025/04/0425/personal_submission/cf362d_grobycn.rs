//! core logic only
//! submission: https://codeforces.com/problemset/submission/362/317182971
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, mut p: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    use std::cmp::Reverse;
    use std::collections::BinaryHeap;

    if q == n && p > 0 {
        return Err("NO");
    }

    let mut uf = UnionFind::new(n);
    let mut weight = vec![0; n];
    let mut region = n;
    let mut pair = (0, 0);
    for (mut x, mut y, l) in scanner.iter::<(usize, usize, usize)>(m) {
        pair = (x, y);
        (x, y) = (x - 1, y - 1);
        let (xp, yp) = (uf.find(x), uf.find(y));
        if uf.union(xp, yp) {
            region -= 1;
            let rt = uf.find(xp);
            weight[rt] = weight[xp] + weight[yp] + l;
        } else {
            weight[xp] += l;
        }
    }

    if region < q || region > q + p {
        return Err("NO");
    }

    let mut hp = BinaryHeap::new();
    for (i, &w) in weight.iter().enumerate() {
        if i == uf.find(i) {
            hp.push((Reverse(w), i));
        }
    }

    let mut ans = vec![];
    while region > q {
        let (Reverse(w1), u) = hp.pop().unwrap();
        let (Reverse(w2), v) = hp.pop().unwrap();
        ans.push((u + 1, v + 1));
        pair = (u + 1, v + 1);
        let w = (w1 + w2 + 1).min(1_000_000_000);
        uf.union(u, v);
        let rt = uf.find(u);
        hp.push((Reverse(w + w1 + w2), rt));
        region -= 1;
        p -= 1;
    }

    ans.extend(std::iter::repeat(pair).take(p));
    Ok("YES".cr().then(Sep::<_, '\n'>(ans)))
}

struct UnionFind {
    parent: Vec<usize>,
    size: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect(),
            size: vec![0; n],
        }
    }
    fn find(&mut self, x: usize) -> usize {
        if x == self.parent[x] {
            return x;
        }
        self.parent[x] = self.find(self.parent[x]);
        self.parent[x]
    }
    fn union(&mut self, x: usize, y: usize) -> bool {
        let (mut xp, mut yp) = (self.find(x), self.find(y));
        if xp != yp {
            if self.size[xp] < self.size[yp] {
                std::mem::swap(&mut xp, &mut yp);
            }
            self.size[xp] += self.size[yp];
            self.parent[yp] = xp;
            true
        } else {
            false
        }
    }
}
