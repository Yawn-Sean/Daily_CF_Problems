//! core logic only
//! submission: https://codeforces.com/problemset/submission/587/290537597
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, l: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_unstable_by_key(|&i| a[i]);

    let (q, rem) = (l / n, l % n);
    let mut ans = l % MOD;
    let mut dp = vec![1; n];
    for x in 2..=k.min(q + 1) {
        let mut r = 0;
        let mut sum = 0;
        let mut ndp = vec![0; n];
        for &i in &indices {
            while r < n && a[indices[r]] <= a[i] {
                sum += dp[indices[r]];
                sum %= MOD;
                r += 1;
            }
            ndp[i] = sum;
        }
        dp = ndp;
        if q + 1 > x {
            let sum = dp.iter().fold(0, |acc, &x| (acc + x) % MOD);
            ans += ((q + 1 - x) % MOD) * sum;
            ans %= MOD;
        }
        let sum = dp.iter().take(rem).fold(0, |acc, &x| (acc + x) % MOD);
        ans += sum;
        ans %= MOD;
    }
    ans
}
