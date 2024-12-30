//! core logic only
//! submission: https://codeforces.com/problemset/submission/228/298196093
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut a, mut b, c) in scanner.iter::<(usize, usize, u8)>(m) {
        (a, b) = (a - 1, b - 1);
        adj[a].push((b, c));
        adj[b].push((a, c));
    }

    fn dfs(adj: &[Vec<(usize, u8)>], cur: usize, from: usize, rev: &mut [u8]) -> bool {
        let mut flip = rev[cur];
        for &(next, c) in &adj[cur] {
            if next == from {
                continue;
            }
            let flip = flip ^ c ^ 1;
            if rev[next] == u8::MAX {
                rev[next] = flip;
                if !dfs(adj, next, cur, rev) {
                    return false;
                }
            } else if rev[next] != flip {
                return false;
            }
        }
        true
    }

    let mut rev = vec![u8::MAX; n];
    for i in 0..n {
        if rev[i] != u8::MAX {
            continue;
        }
        rev[i] = 0;
        if !dfs(&adj, i, i, &mut rev) {
            return Err("Impossible");
        }
    }
    Ok(rev
        .iter()
        .filter(|&&r| r == 1)
        .count()
        .cr()
        .then(Sep::<_, ' '>(
            rev.into_iter()
                .enumerate()
                .filter_map(|(i, r)| if r == 1 { Some(i + 1) } else { None }),
        )))
}
