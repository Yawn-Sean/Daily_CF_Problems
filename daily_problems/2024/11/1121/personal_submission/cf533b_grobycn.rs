//! core logic only
//! submission: https://codeforces.com/problemset/submission/533/292636856
const MULTIPLE_TEST: bool = false;

fn solver(emp: Vec<(i32, i64)>) -> impl Printable {
    let n = emp.len();
    let mut dp = vec![[0, i64::MIN]; n];
    // even[p] = even[i], odd[i] + a[p]
    for (i, &(pi, ai)) in emp.iter().enumerate().rev() {
        dp[i][1] = dp[i][1].max(dp[i][0] + ai);
        if pi != -1 {
            let p = pi as usize - 1;
            let even = (dp[p][0] + dp[i][0]).max(dp[p][1] + dp[i][1]);
            let odd = (dp[p][0] + dp[i][1]).max(dp[p][1] + dp[i][0]);
            dp[p] = [even, odd];
        }
    }
    dp[0][1]
}
