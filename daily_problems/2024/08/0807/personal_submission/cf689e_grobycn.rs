//! core logic only
//! submission: https://codeforces.com/problemset/submission/689/275107064
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

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

fn solver(n: usize, k: i64, scanner: &mut Scanner) -> impl Printable {
    use std::collections::BTreeMap;
    let mut diff = BTreeMap::new();
    for (l, r) in scanner.iter::<(i64, i64)>(n) {
        *diff.entry(l).or_insert(0) += 1;
        *diff.entry(r + 1).or_insert(0) -= 1;
    }
    let mut factorials = vec![1; n + 1];
    for i in 1..=n {
        factorials[i] = (factorials[i - 1] * i) % MOD;
    }
    let mut inv_fact = vec![0; n + 1];
    inv_fact[n] = powermod(factorials[n], MOD - 2, MOD);
    for i in (0..n).rev() {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }

    let comb = |n: usize, k: usize| {
        ((factorials[n] * inv_fact[k]) % MOD * inv_fact[n - k]) % MOD
    };

    let mut sum = 0;
    let mut l = i64::MIN;
    let mut ans = 0;
    for (&i, &d) in diff.iter() {
        if sum >= k {
            let len = ((i - l) as usize) % MOD;
            ans = (ans + comb(sum as _, k as _) * len) % MOD;
        }
        sum += d;
        l = i;
    }
    ans
}
