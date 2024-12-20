//! core logic only
//! submission: https://codeforces.com/problemset/submission/165/297445862
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let mut edges = Vec::with_capacity(n - 1);
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(n - 1) {
        (u, v) = (u - 1, v - 1);
        adj[u].push(v);
        adj[v].push(u);
        edges.push((u, v));
    }

    fn dfs(
        adj: &[Vec<usize>],
        cur: usize,
        fa: usize,
        parent: &mut [usize],
        depth: &mut [usize],
        enter: &mut [usize],
        leave: &mut [usize],
        clock: &mut usize,
    ) {
        enter[cur] = *clock;
        *clock += 1;
        for &next in &adj[cur] {
            if next == fa {
                continue;
            }
            parent[next] = cur;
            depth[next] = depth[cur] + 1;
            dfs(adj, next, cur, parent, depth, enter, leave, clock);
        }
        leave[cur] = *clock;
    }

    let mut lift = vec![vec![0; n]; 18];
    let mut depth = vec![0; n];
    let mut left = vec![0; n];
    let mut right = vec![0; n];
    dfs(
        &adj,
        0,
        0,
        &mut lift[0],
        &mut depth,
        &mut left,
        &mut right,
        &mut 0,
    );

    for i in 1..18 {
        for j in 0..n {
            let p = lift[i - 1][j];
            lift[i][j] = lift[i - 1][p];
        }
    }

    let lca = |mut u: usize, mut v: usize| {
        if depth[u] > depth[v] {
            std::mem::swap(&mut u, &mut v);
        }
        let d = depth[v] - depth[u];
        for (i, lift) in lift.iter().enumerate() {
            if d & (1 << i) != 0 {
                v = lift[v];
            }
        }
        if u == v {
            return u;
        }
        for lift in lift.iter().rev() {
            if lift[u] != lift[v] {
                (u, v) = (lift[u], lift[v]);
            }
        }
        lift[0][u]
    };

    let mut tr = Fenwick::new(n);

    let mut ans = vec![];
    let m = usize::from_scanner(scanner);
    for _ in 0..m {
        let t = u8::from_scanner(scanner);
        if t == 3 {
            let (mut u, mut v) = <(usize, usize)>::from_scanner(scanner);
            (u, v) = (u - 1, v - 1);
            let p = lca(u, v);
            if tr.query_(left[u] + 1) + tr.query_(left[v] + 1) == 2 * tr.query_(left[p] + 1) {
                ans.push((depth[u] + depth[v] - 2 * depth[p]) as i32);
            } else {
                ans.push(-1);
            }
        } else {
            let d = if t == 1 { -1 } else { 1 };
            let e = usize::from_scanner(scanner) - 1;
            let (u, v) = edges[e];
            let s = if depth[u] > depth[v] { u } else { v };
            tr.inc(left[s], d);
            tr.inc(right[s], -d);
        }
    }
    Sep::<_, '\n'>(ans)
}

struct Fenwick {
    arr: Vec<i64>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    fn inc(&mut self, mut i: usize, d: i64) {
        while i < self.arr.len() {
            self.arr[i] += d;
            i += (i + 1) & !i;
        }
    }
    fn query_(&self, mut r: usize) -> i64 {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
}
