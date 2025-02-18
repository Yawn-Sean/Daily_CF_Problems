//! core logic only
//! submission: https://codeforces.com/problemset/submission/412/287517464
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (a, b) in scanner.iter::<(usize, usize)>(m) {
        adj[a - 1].push(b - 1);
    }

    fn dfs(adj: &[Vec<usize>], cur: usize, vis: &mut [bool], ans: &mut Vec<usize>) {
        vis[cur] = true;
        for &next in &adj[cur] {
            if vis[next] {
                continue;
            }
            dfs(adj, next, vis, ans);
        }
        ans.push(cur + 1);
    }

    let mut ans = Vec::with_capacity(n);
    let mut vis = vec![false; n];
    for i in 0..n {
        if vis[i] {
            continue;
        }
        dfs(&adj, i, &mut vis, &mut ans);
    }

    Sep::<_, ' '>(ans)
}
