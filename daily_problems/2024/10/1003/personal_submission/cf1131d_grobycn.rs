//! core logic only
//! submission: https://codeforces.com/problemset/submission/1131/284108311
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::VecDeque;

    let relation: Vec<String> = scanner.iter(n).collect();
    let mut uf = UnionFind::new(n + m);
    for (i, r) in relation.iter().enumerate() {
        for (j, sym) in r.bytes().enumerate() {
            if sym == b'=' {
                uf.union(i, n + j);
            }
        }
    }

    let mut adj = vec![vec![]; n + m];
    let mut deg = vec![0; n + m];
    for (i, r) in relation.iter().enumerate() {
        for (j, sym) in r.bytes().enumerate() {
            let (pi, pj) = (uf.find(i), uf.find(n + j));
            if (sym == b'=') ^ (pi == pj) {
                return Err("NO");
            }
            if sym == b'<' {
                adj[pi].push(pj);
                deg[pj] += 1;
            } else if sym == b'>' {
                adj[pj].push(pi);
                deg[pi] += 1;
            }
        }
    }

    let mut evals = vec![1; n + m];
    let mut queue = VecDeque::new();
    for i in 0..n + m {
        if deg[i] == 0 {
            queue.push_back(i);
        }
    }

    let mut dealed = 0;
    while let Some(cur) = queue.pop_front() {
        dealed += 1;
        for &next in &adj[cur] {
            deg[next] -= 1;
            evals[next] = evals[next].max(evals[cur] + 1);
            if deg[next] == 0 {
                queue.push_back(next);
            }
        }
    }

    if dealed != n + m {
        return Err("NO");
    }
    for i in 0..n + m {
        let pi = uf.find(i);
        evals[i] = evals[pi];
    }
    Ok("YES"
        .cr()
        .then(Sep::<_, ' '>(evals[..n].to_vec()))
        .cr()
        .then(Sep::<_, ' '>(evals[n..].to_vec())))
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
        let mut ret = self.parent[x];
        if x == ret {
            return ret;
        }
        ret = self.find(ret);
        self.parent[x] = ret;
        ret
    }
    fn union(&mut self, x: usize, y: usize) {
        let (mut xp, mut yp) = (self.find(x), self.find(y));
        if xp != yp {
            self.parent[xp] = yp;
        }
    }
}
