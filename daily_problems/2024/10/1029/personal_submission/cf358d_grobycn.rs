//! core logic only
//! submission: https://codeforces.com/problemset/submission/358/288751572
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let b: Vec<usize> = scanner.iter(n).collect();
    let c: Vec<usize> = scanner.iter(n).collect();
    if n == 1 {
        return a[0];
    } else if n == 2 {
        return (a[0] + b[1]).max(a[1] + b[0]);
    }

    let mut dp = vec![vec![0; 2]; n];
    dp[n - 1][0] = a[n - 1];
    dp[n - 1][1] = b[n - 1];
    for i in (0..n - 1).rev() {
        dp[i][0] = (dp[i + 1][0] + b[i]).max(dp[i + 1][1] + a[i]);
        dp[i][1] = (dp[i + 1][0] + c[i]).max(dp[i + 1][1] + b[i]);
    }
    dp[0][0]
}
