//! core logic only
//! submission: https://codeforces.com/problemset/submission/1610/298548135
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

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut count = vec![0; 30];
    for x in scanner.iter::<usize>(n) {
        count[x.trailing_zeros() as usize] += 1;
    }
    let mut rest = n - count[0];
    // sequence contains at least one odd number
    let mut ans = (powermod(2, n, MOD) + MOD - powermod(2, rest, MOD)) % MOD;
    for &c in &count[1..] {
        if c == 0 {
            continue;
        }
        rest -= c;
        let a = powermod(2, c - 1, MOD) - 1;
        let b = powermod(2, rest, MOD);
        ans = (ans + a * b) % MOD;
    }
    ans
}
