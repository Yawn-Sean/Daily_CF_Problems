//! core logic only
//! submission: https://codeforces.com/problemset/submission/1866/309356173
const MULTIPLE_TEST: bool = false;
const MOD: usize = 998_244_353;

fn powermod(mut e: usize, mut x: usize, m: usize) -> usize {
    let mut ret = 1;
    while x != 0 {
        if x & 1 != 0 {
            ret = (ret * e) % m;
        }
        x >>= 1;
        e = (e * e) % m;
    }
    ret
}

fn solver(n: usize, k: usize) -> impl Printable {
    let mut ans = 0;
    let mut last = 0;
    let mut fac = 1;
    let mut mult = 1;
    for e in (n.saturating_sub(k)..=n).rev() {
        // g = (n - e + 1)! * (n - e + 1)^(k - (n - e))
        fac = (fac * (n + 1 - e)) % MOD;
        let g = (fac * powermod(n + 1 - e, k - (n - e), MOD)) % MOD;
        // mult = n!/e!
        ans = (ans + mult * (g + MOD - last)) % MOD;
        last = g;
        mult = (mult * e) % MOD;
    }
    ans
}
