// core logic only
// submission: https://codeforces.com/problemset/submission/611/269953498
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, s: String) -> impl Printable {
    let s = s.as_bytes();
    if s[0] == b'0' {
        return 0;
    }

    let mut common_prefix = vec![vec![0; n + 1]; n + 1];
    for (i, bi) in s.iter().enumerate().rev() {
        for (j, bj) in s[..i].iter().enumerate().rev() {
            if bi == bj {
                common_prefix[j][i] = common_prefix[j + 1][i + 1] + 1;
            }
        }
    }

    let mut dp = vec![vec![0; n]; n];
    dp[0].iter_mut().for_each(|c| *c = 1);
    for beg in 1..n {
        if s[beg] == b'0' {
            continue;
        }
        let mut sum = 0;
        for end in beg..n {
            let len = end + 1 - beg;
            let mut cnt = sum;
            if beg >= len {
                let prefix = common_prefix[beg - len][beg];
                if prefix < len && s[beg - len + prefix] < s[beg + prefix] {
                    cnt = (cnt + dp[beg - len][beg - 1]) % MOD;
                }
                sum = (sum + dp[beg - len][beg - 1]) % MOD;
            }
            dp[beg][end] = cnt;
        }
    }

    (0..n)
        .map(|beg| dp[beg][n - 1])
        .fold(0, |acc, c| (acc + c) % MOD)
}
