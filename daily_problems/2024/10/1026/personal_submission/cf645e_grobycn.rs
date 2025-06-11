//! core logic only
//! submission: https://codeforces.com/problemset/submission/645/288091900
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, k: usize, t: String) -> impl Printable {
    let mut last = vec![0; k];
    let mut dp = vec![0; k];
    let mut sum = 0;
    for (i, b) in t.bytes().enumerate() {
        let idx = (b - b'a') as usize;
        last[idx] = i + 1;
        sum = (sum + MOD - dp[idx]) % MOD;
        dp[idx] = (sum + dp[idx] + 1) % MOD;
        sum = (sum + dp[idx]) % MOD;
    }
    let mut order: Vec<_> = (0..k).collect();
    order.sort_unstable_by_key(|&i| last[i]);
    for idx in std::iter::repeat(order).flatten().take(n) {
        sum = (sum + MOD - dp[idx]) % MOD;
        dp[idx] = (sum + dp[idx] + 1) % MOD;
        sum = (sum + dp[idx]) % MOD;
    }
    (sum + 1) % MOD
}
