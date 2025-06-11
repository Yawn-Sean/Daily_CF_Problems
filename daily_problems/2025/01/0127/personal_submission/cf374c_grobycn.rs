//! core logic only
//! submission: https://codeforces.com/problemset/submission/374/303228285
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let table: Vec<_> = scanner.iter(n).map(String::into_bytes).collect();
    let mut vis = vec![vec![-1; m]; n];

    let mut mx = 0;
    for r in 0..n {
        for c in 0..m {
            if vis[r][c] == -1 {
                if !dfs(&table, r, c, &mut vis) {
                    return Err("Poor Inna!");
                }
            }
            if table[r][c] == b'D' {
                mx = mx.max(vis[r][c]);
            }
        }
    }
    if mx < 4 {
        return Err("Poor Dima!");
    }
    Ok(mx / 4)
}

fn dfs(table: &[Vec<u8>], r: usize, c: usize, vis: &mut [Vec<i32>]) -> bool {
    vis[r][c] = 0;
    let next = match table[r][c] {
        b'D' => b'I',
        b'I' => b'M',
        b'M' => b'A',
        _ => b'D',
    };
    let (n, m) = (table.len(), table[0].len());
    let mut mx = 0;
    for (i, j) in [
        (r.saturating_sub(1), c),
        (r + 1, c),
        (r, c.saturating_sub(1)),
        (r, c + 1),
    ] {
        if i < n && j < m && table[i][j] == next {
            if vis[i][j] == 0 {
                return false;
            }
            if vis[i][j] == -1 {
                if !dfs(table, i, j, vis) {
                    return false;
                }
            }
            mx = mx.max(vis[i][j]);
        }
    }
    vis[r][c] = mx + 1;
    true
}
