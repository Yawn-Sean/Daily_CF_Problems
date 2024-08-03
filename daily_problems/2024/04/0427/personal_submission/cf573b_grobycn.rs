// core logic only
// submission: https://codeforces.com/problemset/submission/573/258382134
const MULTIPLE_TEST: bool = false;

fn solver(h: Vec<usize>) -> impl Printable {
    let n = h.len();
    let mut dp = vec![0; n + 1];
    for (i, &hi) in h.iter().enumerate() {
        dp[i + 1] = (dp[i] + 1).min(hi);
    }
    dp[n] = 1;
    for i in (0..n).rev() {
        dp[i] = dp[i].min(dp[i + 1] + 1);
    }
    *dp.iter().max().unwrap()
}
