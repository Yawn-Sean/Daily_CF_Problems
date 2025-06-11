//! core logic only
//! submission: https://codeforces.com/problemset/submission/1280/290237500
const MULTIPLE_TEST: bool = true;

fn solver(k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; 2 * k];
    for (mut a, mut b, t) in scanner.iter::<(usize, usize, usize)>(2 * k - 1) {
        (a, b) = (a - 1, b - 1);
        adj[a].push((b, t));
        adj[b].push((a, t));
    }

    fn dfs(
        adj: &[Vec<(usize, usize)>],
        cur: usize,
        from: usize,
        g: &mut usize,
        b: &mut usize,
    ) -> usize {
        let mut size = 1;
        let n = adj.len();
        for &(next, t) in &adj[cur] {
            if next == from {
                continue;
            }
            let sz = dfs(adj, next, cur, g, b);
            *g += (sz & 1) * t;
            *b += sz.min(n - sz) * t;
            size += sz;
        }
        size
    }

    let (mut g, mut b) = (0, 0);
    dfs(&adj, 0, 0, &mut g, &mut b);
    (g, b)
}
