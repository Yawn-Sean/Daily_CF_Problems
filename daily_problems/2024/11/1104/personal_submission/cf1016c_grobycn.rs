//! core logic only
//! submission: https://codeforces.com/problemset/submission/1016/289939017
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let b: Vec<usize> = scanner.iter(n).collect();

    // dp[0] start from top left, go right first
    // dp[1] start from top left, go down first
    // dp[2] start from bottom left, go right first
    // dpp[3] start from bottom left, go up first
    let mut dp = [0; 4];
    let mut sum = 0;
    for (i, (&ai, &bi)) in a.iter().zip(&b).enumerate().rev() {
        let mut ndp = [0; 4];
        let rcnt = 2 * (n - 1 - i);
        ndp[0] = dp[0] + sum + (rcnt + 1) * bi;
        ndp[1] = bi + dp[2].max(dp[3]) + sum * 2;
        ndp[2] = dp[2] + sum + (rcnt + 1) * ai;
        ndp[3] = ai + dp[0].max(dp[1]) + sum * 2;
        sum += ai + bi;
        dp = ndp;
    }
    dp[0].max(dp[1])
}
