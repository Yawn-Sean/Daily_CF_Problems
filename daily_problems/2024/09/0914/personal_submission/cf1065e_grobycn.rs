//! core logic only
//! submission: https://codeforces.com/problemset/submission/1065/281370102
const MULTIPLE_TEST: bool = false;
const MOD: usize = 998_244_353;
const INV2: usize = 499_122_177;

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

fn solver(mut n: usize, m: usize, a: usize, scanner: &mut Scanner) -> impl Printable {
    let a = a % MOD;
    let mut ans = if n & 1 != 0 { a } else { 1 };
    n >>= 1;

    let inva1 = powermod(a, MOD - 2, MOD);

    let mut l = 0;
    for b in scanner.iter::<usize>(m) {
        let d = b - l;
        let a = powermod(a, d, MOD);
        let tot = (((a * (a + 1)) % MOD) * INV2) % MOD;
        ans = (ans * tot) % MOD;
        l = b;
    }
    if n != l {
        let d = n - l;
        ans = (ans * powermod(a, 2 * d, MOD)) % MOD;
    }
    ans
}
