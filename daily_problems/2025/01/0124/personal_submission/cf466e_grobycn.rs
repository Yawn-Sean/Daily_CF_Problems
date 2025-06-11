//! core logic only
//! submission: https://codeforces.com/problemset/submission/466/302748690
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let mut uf = UnionFind::new(n);
    let mut docs = vec![];
    let mut queries = vec![];
    for _ in 0..m {
        match u8::from_scanner(scanner) {
            1 => {
                let (mut c, mut p) = <(usize, usize)>::from_scanner(scanner);
                (c, p) = (c - 1, p - 1);
                adj[p].push(c);
                uf.union(c, p);
            }
            2 => {
                let x = usize::from_scanner(scanner) - 1;
                let p = uf.find(x);
                docs.push((x, p));
            }
            _ => {
                let (mut x, mut i) = <(usize, usize)>::from_scanner(scanner);
                (x, i) = (x - 1, i - 1);
                queries.push((i, x));
            }
        }
    }

    let mut enter = vec![usize::MAX; n];
    let mut leave = vec![0; n];
    let mut clock = 0;
    for i in 0..n {
        let p = uf.find(i);
        if enter[p] == usize::MAX {
            dfs(&adj, p, &mut enter, &mut leave, &mut clock);
        }
    }

    let is_ancestor = move |c: usize, p: usize| enter[p] <= enter[c] && leave[c] <= leave[p];
    let ans = queries.into_iter().map(move |(i, x)| {
        let (lo, hi) = docs[i];
        if is_ancestor(lo, x) && is_ancestor(x, hi) {
            "YES"
        } else {
            "NO"
        }
    });
    Sep::<_, '\n'>(ans)
}

fn dfs(adj: &[Vec<usize>], cur: usize, enter: &mut [usize], leave: &mut [usize], clk: &mut usize) {
    enter[cur] = *clk;
    *clk += 1;
    for &next in &adj[cur] {
        dfs(adj, next, enter, leave, clk);
    }
    leave[cur] = *clk;
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
            return x;
        }
        self.parent[x] = self.find(self.parent[x]);
        self.parent[x]
    }
    fn union(&mut self, son: usize, fa: usize) {
        self.parent[son] = self.find(fa);
    }
}
