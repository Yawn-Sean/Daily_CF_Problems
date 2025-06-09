//! core logic only
//! submission: https://codeforces.com/problemset/submission/2073/317899560
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut pos = vec![0; n];
    for (i, x) in scanner.iter::<usize>(n).enumerate() {
        pos[x - 1] = i;
    }
    let mut dp = vec![vec![0; n]; n];
    for len in 2..=n {
        for s in 0..=n - len {
            let e = s + len - 1;
            let mut mn = usize::MAX;
            for i in s..e {
                mn = mn.min(dp[s][i] + dp[i + 1][e] + pos[i + 1].abs_diff(pos[s]));
            }
            dp[s][e] = mn;
        }
    }

    dp[0][n - 1]
}
