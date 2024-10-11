// core logic only
// submission: https://codeforces.com/problemset/submission/156/271189717
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(t: usize, scanner: &mut Scanner) -> impl Printable {
    let mut dp = vec![vec![0; 2501]; 101];
    dp[0][0] = 1;

    for len in 1..=100 {
        for sum in 0..=25 * (len - 1) {
            for x in 0..26 {
                dp[len][sum + x] += dp[len - 1][sum];
                dp[len][sum + x] %= MOD;
            }
        }
    }

    let ans: Vec<_> = scanner.iter(t)
        .map(|s: String| {
            let sum = s.bytes()
                .map(|b| (b - b'a') as usize)
                .sum::<usize>();
            (dp[s.len()][sum] + MOD - 1) % MOD
        }).collect();
    Sep::<_, '\n'>(ans)
}
