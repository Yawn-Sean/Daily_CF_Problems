//! core logic only
//! submission: https://codeforces.com/problemset/submission/223/293368725
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn powermod(mut e: usize, mut x: usize, m: usize) -> usize {
    let mut ret = 1;
    while x > 0 {
        if x & 1 != 0 {
            ret = (ret * e) % m;
        }
        x >>= 1;
        e = (e * e) % m;
    }
    ret
}

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let mut fac = vec![0; n + 1];
    let mut ifac = vec![0; n + 1];
    fac[0] = 1;
    for i in 1..=n {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    ifac[n] = powermod(fac[n], MOD - 2, MOD);
    for i in (1..=n).rev() {
        ifac[i - 1] = (ifac[i] * i) % MOD;
    }

    let mut acc = vec![0; n];
    acc[0] = 1;
    for i in 1..n {
        acc[i] = (acc[i - 1] * (k + i - 1)) % MOD;
        acc[i] = (acc[i] * fac[i - 1]) % MOD;
        acc[i] = (acc[i] * ifac[i]) % MOD;
    }

    Sep::<_, ' '>((1..=n).map(move |i| {
        a.iter()
            .take(i)
            .zip(acc.iter().take(i).rev())
            .map(|(&x, &c)| (x * c) % MOD)
            .fold(0, |acc, x| (acc + x) % MOD)
    }))
}
