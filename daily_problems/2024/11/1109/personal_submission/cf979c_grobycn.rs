//! core logic only
//! submission: https://codeforces.com/problemset/submission/979/290652075
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, mut x: usize, mut y: usize, scanner: &mut Scanner) -> impl Printable {
    match n {
        1 => 0,
        2 => 1,
        _ => {
            let mut adj = vec![vec![]; n];
            for (mut a, mut b) in scanner.iter::<(usize, usize)>(n - 1) {
                (a, b) = (a - 1, b - 1);
                adj[a].push(b);
                adj[b].push(a);
            }

            fn dfs(
                adj: &[Vec<usize>],
                cur: usize,
                from: usize,
                root: usize,
                target: usize,
                exclude: &mut usize,
            ) -> (bool, usize) {
                let (mut found, mut size) = (cur == target, 1);
                for &next in &adj[cur] {
                    if next == from {
                        continue;
                    }
                    let (f, sz) = dfs(adj, next, cur, root, target, exclude);
                    if cur == root && f {
                        *exclude *= adj.len() - sz;
                    }
                    found |= f;
                    size += sz;
                }
                if cur == target {
                    *exclude *= size;
                }
                (found, size)
            }

            let mut exclude = 1;
            let (root, target) = (x - 1, y - 1);
            dfs(&adj, root, root, root, target, &mut exclude);
            n * (n - 1) - exclude
        }
    }
}
