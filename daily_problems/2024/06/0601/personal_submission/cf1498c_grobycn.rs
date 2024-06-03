// core logic only
// submission: https://codeforces.com/contest/1498/submission/263592199
const MULTIPLE_TEST: bool = true;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, k: usize) -> impl Printable {
    let mut dp = vec![1; n + 1];
    let mut tmp = vec![0; n + 1];
    for _ in 2..=k {
        std::mem::swap(&mut dp, &mut tmp);
        let mut sum = 0;
        dp[0] = 1;
        for (c, &x) in dp[1..].iter_mut().zip(tmp[..n].iter().rev()) {
            sum = (sum + x) % MOD;
            *c = (1 + sum) % MOD;
        }
    }
    dp[n]
}
