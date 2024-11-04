//! core logic only
//! submission: https://codeforces.com/problemset/submission/336/280998619
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, m: usize, g: usize) -> impl Printable {
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

    fn dp(n: usize, m: usize, g: usize, comb: &impl Fn(usize, usize) -> usize) -> usize {
        if n + m == 1 {
            return usize::from(m == g);
        }
        let mut ans = 0;
        if n > 0 {
            ans += dp(n - 1, m, 1 - g, comb);
        }
        if g == 0 && m > 0 {
            ans += comb(n + m - 1, n);
        }
        ans % MOD
    }

    let mut fac = vec![1; n + m];
    for i in 1..n + m {
        fac[i] = (fac[i - 1] * i) % MOD;
    }

    let mut inv_fac = vec![0; n + m];
    inv_fac[n + m - 1] = powermod(fac[n + m - 1], MOD - 2, MOD);
    for i in (1..n + m).rev() {
        inv_fac[i - 1] = (inv_fac[i] * i) % MOD;
    }

    let comb = |n: usize, k: usize| (((fac[n] * inv_fac[k]) % MOD) * inv_fac[n - k]) % MOD;
    dp(n, m, g, &comb)
}
