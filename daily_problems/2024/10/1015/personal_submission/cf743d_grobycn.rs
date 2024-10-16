//! core logic only
//! submission: https://codeforces.com/problemset/submission/743/286077565
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<i64>, scanner: &mut Scanner) -> impl Printable {
    let n = a.len();
    let mut adj = vec![vec![]; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(n - 1) {
        (u, v) = (u - 1, v - 1);
        adj[u].push(v);
        adj[v].push(u);
    }

    fn dfs(
        adj: &[Vec<usize>],
        cur: usize,
        from: usize,
        pleasantness: &[i64],
        ans: &mut i64,
    ) -> (i64, i64) {
        let (mut max, mut sum) = (i64::MIN, pleasantness[cur]);
        for &next in &adj[cur] {
            if next == from {
                continue;
            }
            let (mx, sm) = dfs(adj, next, cur, pleasantness, ans);
            sum += sm;
            if max != i64::MIN {
                *ans = (max + mx).max(*ans);
            }
            max = max.max(mx);
        }
        max = max.max(sum);
        (max, sum)
    }

    let mut ans = i64::MIN;
    dfs(&adj, 0, 0, &a, &mut ans);
    if ans == i64::MIN {
        return Err("Impossible");
    }
    Ok(ans)
}
