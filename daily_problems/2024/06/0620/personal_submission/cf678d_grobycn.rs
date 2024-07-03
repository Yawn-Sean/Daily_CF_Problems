// core logic only
// submission: https://codeforces.com/problemset/submission/678/266960116
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(a: usize, b: usize, n: usize, x: usize) -> impl Printable {
    // g^0(x) = x
    // f(x) = ax + b
    // g^n(x) = f(g^{n - 1}(x))
    // g^1(x) = ax + b
    // g^2(x) = a(ax + b) + b
    // g^3(x) = a(a(ax + b) + b) + b
    // ...
    // g^n(x) = a^n x + b(1 + a + a^2 + ... + a^{n - 1})
    let an = powermod(a, n, MOD);
    if a == 1 {
        return ((an * x) % MOD + (b * (n % MOD)) % MOD) % MOD;
    }
    ((an * x) % MOD + ((((an - 1) * b) % MOD) * powermod(a - 1, MOD - 2, MOD))) % MOD
}

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
