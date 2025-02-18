//! core logic only
//! submission: https://codeforces.com/problemset/submission/900/283873981
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, s: String, m: usize) -> impl Printable {
    use std::cmp::Reverse;
    let mut presum = vec![0; n + 1];
    for (i, b) in s.bytes().enumerate() {
        presum[i + 1] = presum[i] + usize::from(b == b'?');
    }
    let mut alt = vec![vec![0; n + 1]; 2];
    for (i, b) in s.bytes().enumerate().rev() {
        if b != b'a' {
            alt[1][i] = alt[0][i + 1] + 1;
        }
        if b != b'b' {
            alt[0][i] = alt[1][i + 1] + 1;
        }
    }

    let mut dp = vec![(0, Reverse(0)); n + 1];
    for i in 0..n {
        dp[i + 1] = dp[i + 1].max(dp[i]);
        if alt[0][i] >= m {
            let (mut beauty, Reverse(mut op)) = dp[i];
            beauty += 1;
            op += presum[i + m] - presum[i];
            dp[i + m] = dp[i + 1].max((beauty, Reverse(op)));
        }
    }
    dp[n].1 .0
}
