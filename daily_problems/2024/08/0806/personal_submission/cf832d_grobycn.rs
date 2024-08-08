//! core logic only
//! submission: https://codeforces.com/contest/832/submission/275091719
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut p, i) in scanner.iter::<usize>(n - 1).zip(1..) {
        p -= 1;
        adj[i].push(p);
        adj[p].push(i);
    }

    fn dfs(adj: &[Vec<usize>], cur: usize, fa: usize, depth: &mut [usize], lift: &mut [[usize; 20]]) {
        lift[cur][0] = fa;
        for i in 1..20 {
            lift[cur][i] = lift[lift[cur][i - 1]][i - 1];
        }
        for &next in &adj[cur] {
            if next == fa {
                continue;
            }
            depth[next] = depth[cur] + 1;
            dfs(adj, next, cur, depth, lift);
        }
    }

    let mut depth = vec![0; n];
    let mut lift = vec![[usize::MAX; 20]; n];
    dfs(&adj, 0, 0, &mut depth, &mut lift);
    let lca = |mut u: usize, mut v: usize| {
        if depth[u] < depth[v] {
            std::mem::swap(&mut u, &mut v);
        }
        let d = depth[u] - depth[v];
        if d != 0 {
            for i in 0..20 {
                if d & (1 << i) != 0 {
                    u = lift[u][i];
                }
            }
        }
        if u == v {
            return u;
        }
        for i in (0..20).rev() {
            if lift[u][i] != lift[v][i] {
                u = lift[u][i];
                v = lift[v][i];
            }
        }
        lift[u][0]
    };

    let dist = |u: usize, v: usize| {
        let rt = lca(u, v);
        depth[u] + depth[v] - 2 * depth[rt]
    };

    let ans: Vec<_> = scanner.iter::<(usize, usize, usize)>(q)
        .map(|(mut a, mut b, mut c)| {
            (a, b, c) = (a - 1, b - 1, c - 1);
            let dab = dist(a, b);
            let dac = dist(a, c);
            let dbc = dist(b, c);
            (dab + dac + dbc - 2 * dab.min(dac).min(dbc)) / 2 + 1
        }).collect();
    Sep::<_, '\n'>(ans)
}
