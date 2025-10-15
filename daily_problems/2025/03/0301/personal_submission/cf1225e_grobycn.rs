//! core logic only
//! submission: https://codeforces.com/problemset/submission/1225/308943434
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    if n == 1 && m == 1 {
        return 1;
    }
    let map: Vec<_> = scanner.iter(n).map(String::into_bytes).collect();
    if map[n - 1][m - 1] == b'R' {
        return 0;
    }

    let mut rsum = vec![vec![0; m + 1]; n];
    let mut csum = vec![vec![0; m]; n + 1];
    for (r, row) in map.iter().enumerate() {
        for (c, &b) in row.iter().enumerate() {
            let is_rock = usize::from(b == b'R');
            rsum[r][c + 1] = rsum[r][c] + is_rock;
            csum[r + 1][c] = csum[r][c] + is_rock;
        }
    }

    let mut down_right = vec![vec![0; m + 1]; n + 1];
    down_right[n - 1][m - 1] = 1;
    let mut right_down = down_right.clone();
    for r in (0..n).rev() {
        for c in (0..m).rev() {
            if r == n - 1 && c == m - 1 {
                continue;
            }
            let r_empty = m - c - 1 - (rsum[r][m] - rsum[r][c + 1]);
            let d_empty = n - r - 1 - (csum[n][c] - csum[r + 1][c]);
            down_right[r][c] = (right_down[r + 1][c] + MOD - right_down[r + 1 + d_empty][c]) % MOD;
            down_right[r][c] += down_right[r][c + 1];
            down_right[r][c] %= MOD;
            right_down[r][c] = (down_right[r][c + 1] + MOD - down_right[r][c + 1 + r_empty]) % MOD;
            right_down[r][c] += right_down[r + 1][c];
            right_down[r][c] %= MOD;
        }
    }

    (down_right[0][0] + MOD - down_right[0][1] + right_down[0][0] + MOD - right_down[1][0]) % MOD
}
