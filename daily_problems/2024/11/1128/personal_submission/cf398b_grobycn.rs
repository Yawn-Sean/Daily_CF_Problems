//! core logic only
//! submission: https://codeforces.com/problemset/submission/398/293657784
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut row = vec![false; n];
    let mut col = vec![false; n];
    scanner.iter::<(usize, usize)>(m).for_each(|(r, c)| {
        row[r - 1] = true;
        col[c - 1] = true;
    });
    let rcnt = row.into_iter().filter(|&painted| painted).count();
    let ccnt = col.into_iter().filter(|&painted| painted).count();
    let mut dp = vec![vec![0.0; n + 1]; n + 1];
    dp[n][n] = 0.0;
    for r in (rcnt..n).rev() {
        let p = ((n - r) as f64) / (n as f64);
        dp[r][n] = dp[r + 1][n] + 1.0 / p;
    }
    for c in (ccnt..n).rev() {
        let p = ((n - c) as f64) / (n as f64);
        dp[n][c] = dp[n][c + 1] + 1.0 / p;
    }
    for r in (rcnt..n).rev() {
        for c in (ccnt..n).rev() {
            let p1 = ((r * c) as f64) / ((n * n) as f64);
            let p2 = (((n - r) * c) as f64) / ((n * n) as f64);
            let p3 = ((r * (n - c)) as f64) / ((n * n) as f64);
            let p4 = 1.0 - p1 - p2 - p3;
            dp[r][c] =
                (dp[r + 1][c] * p2 + dp[r][c + 1] * p3 + dp[r + 1][c + 1] * p4 + 1.0) / (1.0 - p1);
        }
    }
    dp[rcnt][ccnt]
}
