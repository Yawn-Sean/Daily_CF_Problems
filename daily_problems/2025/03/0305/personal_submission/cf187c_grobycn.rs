//! core logic only
//! submission: https://codeforces.com/problemset/submission/187/309069386
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::VecDeque;
    let mut dist = vec![usize::MAX; n];
    let mut from = vec![usize::MAX; n];
    let mut queue: VecDeque<_> = scanner
        .iter::<usize>(k)
        .map(|x| x - 1)
        .inspect(|&x| dist[x] = 0)
        .inspect(|&x| from[x] = x)
        .collect();
    let edges: Vec<_> = scanner
        .iter::<(usize, usize)>(m)
        .map(|(u, v)| (u - 1, v - 1))
        .collect();
    let mut adj = vec![vec![]; n];
    for &(u, v) in &edges {
        adj[u].push(v);
        adj[v].push(u);
    }

    let (mut s, mut t) = <(usize, usize)>::from_scanner(scanner);
    (s, t) = (s - 1, t - 1);
    queue.push_back(t);
    dist[t] = 0;
    while let Some(cur) = queue.pop_front() {
        for &next in &adj[cur] {
            if dist[next] == usize::MAX {
                dist[next] = dist[cur] + 1;
                from[next] = from[cur];
                queue.push_back(next);
            }
        }
    }

    let mut groups = vec![vec![]; n];
    for &(u, v) in &edges {
        let w = if from[u] == from[v] {
            dist[u].max(dist[v])
        } else {
            dist[u] + dist[v] + 1
        };
        if w < n {
            groups[w].push((u, v));
        }
    }

    let mut uf = UnionFind::new(n);
    for (w, g) in groups.iter().enumerate() {
        for &(u, v) in g {
            uf.union(u, v);
        }
        if uf.find(s) == uf.find(t) {
            return Ok(w);
        }
    }
    Err(-1)
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
            return x;
        }
        self.parent[x] = self.find(self.parent[x]);
        self.parent[x]
    }
    fn union(&mut self, x: usize, y: usize) {
        let (mut xp, mut yp) = (self.find(x), self.find(y));
        if xp != yp {
            if self.size[xp] > self.size[yp] {
                std::mem::swap(&mut xp, &mut yp);
            }
            self.size[yp] += self.size[xp];
            self.parent[xp] = yp;
        }
    }
}
