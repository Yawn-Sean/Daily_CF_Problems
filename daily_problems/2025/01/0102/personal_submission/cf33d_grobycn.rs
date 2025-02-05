//! core logic only
//! submission: https://codeforces.com/problemset/submission/33/299367795
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let cp: Vec<(i64, i64)> = scanner.iter(n).collect();
    let fence: Vec<(i64, i64, i64)> = scanner.iter(m).collect();
    let mut adj = vec![vec![]; m + 1];
    for (&(ri, xi, yi), i) in fence.iter().zip(1..) {
        let mut p = 0;
        for (&(rj, xj, yj), j) in fence.iter().zip(1..) {
            if rj > ri && (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) < rj * rj {
                if p == 0 || fence[p - 1].0 > rj {
                    p = j;
                }
            }
        }
        adj[p].push(i);
    }
    let mut outer = vec![0; n];
    for (i, &(xi, yi)) in cp.iter().enumerate() {
        let mut p = 0;
        for (&(rj, xj, yj), j) in fence.iter().zip(1..) {
            if (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) < rj * rj {
                if p == 0 || fence[p - 1].0 > rj {
                    p = j;
                }
            }
        }
        outer[i] = p;
    }

    fn dfs(adj: &[Vec<usize>], cur: usize, depth: &mut [usize], parent: &mut [usize]) {
        for &next in &adj[cur] {
            depth[next] = depth[cur] + 1;
            parent[next] = cur;
            dfs(adj, next, depth, parent);
        }
    }

    let mut depth = vec![0; m + 1];
    let mut lift = vec![vec![0; m + 1]; 10];
    dfs(&adj, 0, &mut depth, &mut lift[0]);
    for i in 1..10 {
        for x in 0..=m {
            let p = lift[i - 1][x];
            lift[i][x] = lift[i - 1][p];
        }
    }

    let lca = |mut u: usize, mut v: usize| {
        if depth[u] < depth[v] {
            std::mem::swap(&mut u, &mut v);
        }
        let d = depth[u] - depth[v];
        if d > 0 {
            for (i, ps) in lift.iter().enumerate() {
                if d & (1 << i) != 0 {
                    u = ps[u];
                }
            }
        }
        if u == v {
            return u;
        }
        for (i, ps) in lift.iter().enumerate().rev() {
            if ps[u] != ps[v] {
                u = ps[u];
                v = ps[v];
            }
        }
        lift[0][u]
    };

    let ans: Vec<_> = scanner
        .iter::<(usize, usize)>(k)
        .map(|(a, b)| {
            let (a, b) = (outer[a - 1], outer[b - 1]);
            let p = lca(a, b);
            depth[a] + depth[b] - 2 * depth[p]
        })
        .collect();
    Sep::<_, '\n'>(ans)
}
