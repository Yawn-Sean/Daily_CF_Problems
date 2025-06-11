//! core logic only
//! submission: https://codeforces.com/problemset/submission/629/299580419
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut a, mut b) in scanner.iter::<(usize, usize)>(n - 1) {
        (a, b) = (a - 1, b - 1);
        adj[a].push(b);
        adj[b].push(a);
    }

    let mut depth = vec![0; n];
    let mut lift = vec![vec![0; n]; 17];
    let mut size = vec![0; n];
    let mut sum_subtree = vec![0; n];
    dfs(
        &adj,
        0,
        0,
        &mut depth,
        &mut lift[0],
        &mut size,
        &mut sum_subtree,
    );
    for i in 1..17 {
        for x in 0..n {
            let p = lift[i - 1][x];
            lift[i][x] = lift[i - 1][p];
        }
    }
    let mut sum = sum_subtree.clone();
    reroot(&adj, 0, 0, &size, &mut sum);

    let lca = |mut u: usize, mut v: usize| {
        if depth[u] < depth[v] {
            std::mem::swap(&mut u, &mut v);
        }
        let d = depth[u] - depth[v];
        if d != 0 {
            for (i, p) in lift.iter().enumerate() {
                if d & (1 << i) != 0 {
                    u = p[u];
                }
            }
        }
        if u == v {
            return u;
        }
        for (i, p) in lift.iter().enumerate().rev() {
            if p[u] != p[v] {
                (u, v) = (p[u], p[v]);
            }
        }
        lift[0][u]
    };

    let ans: Vec<_> = scanner
        .iter::<(usize, usize)>(m)
        .map(|(mut u, mut v)| {
            (u, v) = (u - 1, v - 1);
            if depth[u] < depth[v] {
                std::mem::swap(&mut u, &mut v);
            }
            let p = lca(u, v);
            let l = depth[u] + depth[v] - 2 * depth[p] + 1;
            let lu = (sum_subtree[u] as f64) / (size[u] as f64);
            let lv = if p == v {
                let d = depth[u] - depth[p] - 1;
                for (i, p) in lift.iter().enumerate() {
                    if d & (1 << i) != 0 {
                        u = p[u];
                    }
                }
                ((sum[p] - sum_subtree[u] - size[u]) as f64) / ((n - size[u]) as f64)
            } else {
                (sum_subtree[v] as f64) / (size[v] as f64)
            };
            l as f64 + lu + lv
        })
        .collect();
    Sep::<_, '\n'>(ans)
}

fn dfs(
    adj: &[Vec<usize>],
    cur: usize,
    fa: usize,
    depth: &mut [usize],
    parent: &mut [usize],
    size: &mut [usize],
    sum: &mut [usize],
) {
    size[cur] = 1;
    sum[cur] = 0;
    for &next in &adj[cur] {
        if next == fa {
            continue;
        }
        depth[next] = depth[cur] + 1;
        parent[next] = cur;
        dfs(adj, next, cur, depth, parent, size, sum);
        size[cur] += size[next];
        sum[cur] += sum[next] + size[next];
    }
}

fn reroot(adj: &[Vec<usize>], cur: usize, fa: usize, size: &[usize], sum: &mut [usize]) {
    let n = adj.len();
    for &next in &adj[cur] {
        if next == fa {
            continue;
        }
        sum[next] = sum[cur] + n - 2 * size[next];
        reroot(adj, next, cur, size, sum);
    }
}
