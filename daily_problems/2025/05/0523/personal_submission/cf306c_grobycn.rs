//! core logic only
//! submission: https://codeforces.com/problemset/submission/306/320910703
const MULTIPLE_TEST: bool = false;

const MOD: usize = 1_000_000_009;
fn powermod(mut e: usize, mut x: usize, m: usize) -> usize {
    let mut ret = 1;
    while x > 0 {
        if x & 1 != 0 {
            ret = (ret * e) % m;
        }
        e = (e * e) % m;
        x >>= 1;
    }
    ret
}

fn solver(n: usize, w: usize, b: usize) -> impl Printable {
    let m = b.max(w);
    let mut fac = vec![1; m + 1];
    for i in 1..=m {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    let mut ifac = vec![0; m + 1];
    ifac[m] = powermod(fac[m], MOD - 2, MOD);
    for i in (1..=m).rev() {
        ifac[i - 1] = (ifac[i] * i) % MOD;
    }
    let comb = |n: usize, k: usize| (((fac[n] * ifac[k]) % MOD) * ifac[n - k]) % MOD;

    let mut ans = 0;
    for bad_days in 1..=b {
        let good_days = n.saturating_sub(bad_days);
        if good_days < 2 {
            break;
        }
        if good_days > w {
            continue;
        }
        let ways = (comb(b - 1, bad_days - 1) * comb(w - 1, good_days - 1)) % MOD;
        ans = (ans + ways * (good_days - 1)) % MOD;
    }
    (((ans * fac[b]) % MOD) * fac[w]) % MOD
}
