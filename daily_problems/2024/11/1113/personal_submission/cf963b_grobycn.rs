//! core logic only
//! submission: https://codeforces.com/problemset/submission/963/291329504
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let mut root = 0;
    for (i, p) in scanner.iter::<usize>(n).enumerate() {
        if p > 0 {
            adj[p - 1].push(i);
        } else {
            root = i;
        }
    }

    fn dfs(
        adj: &[Vec<usize>],
        cur: usize,
        root: usize,
        stk: &mut Vec<usize>,
        ans: &mut Vec<usize>,
    ) -> bool {
        let n = adj.len();
        let mut is_odd = cur != root;
        stk.push(n + cur + 1);
        for &next in &adj[cur] {
            is_odd ^= dfs(adj, next, root, stk, ans);
        }
        stk.push(cur + 1);
        if !is_odd {
            while let Some(node) = stk.pop() {
                if node == n + cur + 1 {
                    break;
                }
                if node <= n {
                    ans.push(node);
                }
            }
        }
        is_odd
    }

    let mut ans = vec![];
    if dfs(&adj, root, root, &mut vec![], &mut ans) {
        Err("NO")
    } else {
        Ok("YES".cr().then(Sep::<_, '\n'>(ans)))
    }
}
