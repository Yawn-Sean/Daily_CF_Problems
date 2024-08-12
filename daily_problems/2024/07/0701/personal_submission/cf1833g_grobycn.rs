// core logic only
// submission: https://codeforces.com/problemset/submission/1833/268330617
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let edges: Vec<(usize, usize)> = scanner.iter(n - 1).collect();
    if n % 3 != 0 {
        return Err(-1);
    }

    let mut adj = vec![vec![]; n];
    for (i, &(u, v)) in edges.iter().enumerate() {
        adj[u - 1].push(i);
        adj[v - 1].push(i);
    }

    fn dfs(
        adj: &[Vec<usize>],
        edges: &[(usize, usize)],
        cur: usize,
        fa: usize,
        ans: &mut Vec<usize>,
    ) -> Option<usize> {
        let mut cnt = 0;
        for &eidx in &adj[cur] {
            let (mut u, mut v) = edges[eidx];
            let next = if u == cur + 1 { v - 1 } else { u - 1 };
            if next == fa {
                continue;
            }
            let rest = dfs(adj, edges, next, cur, ans)?;
            if rest == 0 {
                ans.push(eidx + 1);
            } else {
                cnt += rest;
            }
        }
        if cnt > 2 {
            return None;
        }
        Some((cnt + 1) % 3)
    }

    let mut ans = vec![];
    dfs(&adj, &edges, 0, 0, &mut ans).ok_or(-1)?;
    Ok(ans.len().cr().then(Sep::<_, ' '>(ans)))
}
