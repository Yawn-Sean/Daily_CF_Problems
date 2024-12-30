//! core logic only
//! submission: https://codeforces.com/problemset/submission/494/279817866
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(s: String, t: String) -> impl Printable {
    let m = t.len();
    let mut lps = vec![0; m];
    let mut l = 0;
    let tbs = t.as_bytes();
    for (i, b) in t.bytes().enumerate().skip(1) {
        while b != tbs[l] && l > 0 {
            l = lps[l - 1];
        }
        if b == tbs[l] {
            l += 1;
            lps[i] = l;
        }
    }
    let n = s.len();
    let mut dp = vec![0; n];
    let mut psum = vec![0; n + 1];
    let mut ppsum = vec![0; n + 2];
    psum[0] = 1;
    ppsum[1] = 1;
    l = 0;
    let mut left = 0;
    for (i, b) in s.bytes().enumerate() {
        while b != tbs[l] && l > 0 {
            l = lps[l - 1];
        }
        if b == tbs[l] {
            l += 1;
            if l == m {
                left = i + 2 - m;
                l = lps[l - 1];
            }
        }
        dp[i] = ppsum[left];
        psum[i + 1] = (psum[i] + dp[i]) % MOD;
        ppsum[i + 2] = (ppsum[i + 1] + psum[i + 1]) % MOD;
    }
    (psum[n] + MOD - 1) % MOD
}
