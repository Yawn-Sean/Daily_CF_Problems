//! core logic only
//! submission: https://codeforces.com/problemset/submission/327/299070230
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut g: Vec<_> = scanner.iter::<String>(n).map(|s| s.into_bytes()).collect();

    fn dfs(g: &mut [Vec<u8>], r: usize, c: usize, ops: &mut Vec<(char, usize, usize)>) {
        let (n, m) = (g.len(), g[0].len());
        for (i, j) in [
            (r.wrapping_sub(1), c),
            (r + 1, c),
            (r, c.wrapping_sub(1)),
            (r, c + 1),
        ] {
            if i < n && j < m && g[i][j] == b'.' {
                g[i][j] = b'#';
                ops.push(('B', i + 1, j + 1));
                dfs(g, i, j, ops);
                ops.push(('D', i + 1, j + 1));
                ops.push(('R', i + 1, j + 1));
            }
        }
    }

    let mut ops = vec![];
    for r in 0..n {
        for c in 0..m {
            if g[r][c] == b'.' {
                g[r][c] = b'#';
                ops.push(('B', r + 1, c + 1));
                dfs(&mut g, r, c, &mut ops);
            }
        }
    }
    ops.len().cr().then(Sep::<_, '\n'>(ops))
}
