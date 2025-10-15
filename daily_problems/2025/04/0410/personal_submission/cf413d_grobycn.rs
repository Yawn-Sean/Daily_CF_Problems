//! core logic only
//! submission: https://codeforces.com/problemset/submission/413/314892854
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, mut k: usize, scanner: &mut Scanner) -> impl Printable {
    k -= 1;
    let mut dp = vec![0; (1 << k) + 1];
    dp[0] = 1;

    let mut ans = 0;
    for mut x in scanner.iter::<usize>(n) {
        x >>= 1;
        let mut ndp = vec![0; (1 << k) + 1];
        if x != 1 {
            for (i, &c) in dp[..1 << k].iter().enumerate().step_by(2) {
                ndp[i + 2] = (ndp[i + 2] + c) % MOD;
            }
            for &c in dp[1..1 << k].iter().step_by(2) {
                ndp[2] = (ndp[2] + c) % MOD;
            }
        }
        if x != 2 {
            for (i, &c) in dp[..1 << k].iter().enumerate() {
                ndp[i + 1] = (ndp[i + 1] + c) % MOD;
            }
        }
        dp = ndp;
        if x == 0 {
            ans = (ans * 2) % MOD;
        }
        ans = (ans + dp[1 << k]) % MOD;
    }
    ans
}
