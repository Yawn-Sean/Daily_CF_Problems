//! core logic only
//! submission: https://codeforces.com/problemset/submission/1906/312812723
const MULTIPLE_TEST: bool = false;
const MOD: usize = 998_244_353;

fn solver(a: Vec<usize>) -> impl Printable {
    let n = a.len();
    let mut count = vec![1; n];
    for (i, w) in a.windows(2).enumerate() {
        if w[0] < w[1] {
            count[i + 1] = count[i] + 1;
        }
    }

    let mut dp = vec![0; n];
    dp[0] = 1;
    for front in 1..n {
        let mut acc = vec![0; n];
        std::mem::swap(&mut acc, &mut dp);
        let mut pow = 2;
        for i in front..n {
            acc[i] = ((acc[i] * pow) % MOD + acc[i - 1]) % MOD;
            pow = (pow * 2) % MOD;
        }
        for back in front..n {
            let l = (back + 1 - count[back]).max(front);
            dp[back] = (acc[back] + MOD - if l <= 1 { 0 } else { acc[l - 2] }) % MOD;
        }
    }
    dp[n - 1]
}
