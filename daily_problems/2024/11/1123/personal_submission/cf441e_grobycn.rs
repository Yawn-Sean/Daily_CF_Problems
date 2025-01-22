//! core logic only
//! submission: https://codeforces.com/problemset/submission/441/292864490
const MULTIPLE_TEST: bool = false;

fn solver(x: usize, k: usize, p: usize) -> impl Printable {
    let mut dp: Vec<_> = (x..=x + k).map(|x| x.trailing_zeros() as f64).collect();
    let p = (p as f64) / 100.0;
    for _ in 1..=k {
        let mut ndp = vec![0.0; k + 1];
        for j in 0..=k {
            if j * 2 <= k {
                ndp[2 * j] += (dp[j] + 1.0) * p;
            }
            if j > 0 {
                ndp[j - 1] += dp[j] * (1.0 - p);
            }
        }
        dp = ndp;
    }
    dp[0]
}
