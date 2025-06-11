//! core logic only
//! submission: https://codeforces.com/problemset/submission/681/277529276
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let mut deg = vec![0; n];
    for (p, q) in scanner.iter::<(usize, usize)>(m) {
        adj[p - 1].push(q - 1);
        deg[q - 1] += 1;
    }
    let list: Vec<_> = scanner.iter(n).map(|x: usize| x - 1).collect();
    let mut depth = vec![0; n];
    let mut ans = vec![];

    fn dfs(
        adj: &[Vec<usize>],
        cur: usize,
        depth: &mut [usize],
        ans: &mut Vec<usize>,
        list: &[usize],
    ) -> bool {
        let idx = list[cur];
        for &next in &adj[cur] {
            depth[next] = depth[cur] + 1;
            if !dfs(adj, next, depth, ans, list) {
                return false;
            }
            let to = list[next];
            if to != idx && depth[to] <= depth[cur] {
                return false;
            }
        }
        if idx == cur {
            ans.push(idx + 1);
        }
        true
    }

    for (i, &d) in deg.iter().enumerate() {
        if d == 0 {
            if !dfs(&adj, i, &mut depth, &mut ans, &list) {
                return Err(-1);
            }
        }
    }
    Ok(ans.len().cr().then(Sep::<_, '\n'>(ans)))
}
