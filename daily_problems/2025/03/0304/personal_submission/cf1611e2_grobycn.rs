//! core logic only
//! submission: https://codeforces.com/problemset/submission/1611/308943190
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut has_friend = vec![false; n];
    for mut x in scanner.iter::<usize>(k) {
        has_friend[x - 1] = true;
    }

    let mut adj = vec![vec![]; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(n - 1) {
        adj[u - 1].push(v - 1);
        adj[v - 1].push(u - 1);
    }

    fn dfs(
        adj: &[Vec<usize>],
        cur: usize,
        fa: usize,
        has_friend: &[bool],
        path: &mut Vec<usize>,
        forbid: &mut [bool],
    ) {
        path.push(cur);
        if has_friend[cur] {
            let p = path[path.len() / 2];
            forbid[p] = true;
        }
        for &next in &adj[cur] {
            if next == fa {
                continue;
            }
            dfs(adj, next, cur, has_friend, path, forbid);
        }
        path.pop();
    }

    let mut forbid = vec![false; n];
    let mut path = vec![];
    dfs(&adj, 0, 0, &has_friend, &mut path, &mut forbid);

    fn dfs2(adj: &[Vec<usize>], cur: usize, fa: usize, forbid: &[bool], cnt: &mut usize) -> bool {
        if cur != 0 && adj[cur].len() == 1 {
            return true;
        }
        for &next in &adj[cur] {
            if next == fa {
                continue;
            }
            if forbid[next] {
                *cnt += 1;
                continue;
            }
            if dfs2(adj, next, cur, forbid, cnt) {
                return true;
            }
        }
        false
    }

    let mut ans = 0;
    if dfs2(&adj, 0, 0, &forbid, &mut ans) {
        Err(-1)
    } else {
        Ok(ans)
    }
}
