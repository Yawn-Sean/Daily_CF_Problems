//! core logic only
//! submission: https://codeforces.com/problemset/submission/629/300289972
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, m: usize, s: String) -> impl Printable {
    if n & 1 != 0 {
        return 0;
    }
    let mut lpext = 0;
    let mut lpcnt = 0;
    let mut delta = 0;
    for b in s.bytes() {
        if b == b'(' {
            lpcnt += 1;
            delta += 1;
        } else if delta == 0 {
            lpext += 1;
        } else {
            delta -= 1;
        }
    }
    if lpcnt > n / 2 || m - lpcnt > n / 2 {
        return 0;
    }

    let l = n - m;
    let mut dp = vec![vec![0; l + 1]; l + 1];
    dp[0][0] = 1;
    for i in 1..=l {
        dp[i][0] = dp[i - 1][1];
        for d in 1..i {
            dp[i][d] = (dp[i - 1][d - 1] + dp[i - 1][d + 1]) % MOD;
        }
        dp[i][i] = dp[i - 1][i - 1];
    }

    let mut ans = 0;
    for pre in 0..=l {
        let suf = l - pre;
        for lp in lpext..=pre {
            let rp = lp - lpext + delta;
            if rp > suf {
                break;
            }
            ans += dp[pre][lp] * dp[suf][rp];
            ans %= MOD;
        }
    }
    ans
}
