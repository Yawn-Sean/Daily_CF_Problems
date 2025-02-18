//! core logic only
//! submission: https://codeforces.com/problemset/submission/615/282002994
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let mut deg = vec![0; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(m) {
        (u, v) = (u - 1, v - 1);
        deg[u] += 1;
        deg[v] += 1;
        if u < v {
            std::mem::swap(&mut u, &mut v);
        }
        adj[u].push(v);
    }

    let mut ans = 0usize;
    let mut dp = vec![0; n];
    for (p, children) in adj.iter().enumerate() {
        let mx = children.iter().map(|&i| dp[i]).max().unwrap_or(0);
        dp[p] = mx + 1;
        ans = ans.max(dp[p] * deg[p])
    }
    ans
}
