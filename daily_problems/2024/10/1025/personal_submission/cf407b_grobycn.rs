//! core logic only
//! submission: https://codeforces.com/problemset/submission/407/287942040
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut dp2 = vec![0; n + 1];
    for (i, pi) in scanner.iter::<usize>(n).enumerate() {
        dp2[i + 1] = (2 * dp2[i] + 2 + MOD - dp2[pi - 1]) % MOD;
    }
    dp2[n]
}
