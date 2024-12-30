// core logic only
// submission: https://codeforces.com/contest/1575/submission/264667459
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(
    n: usize,
    m: usize,
    mut k: usize,
    r: usize,
    c: usize,
    ax: usize,
    ay: usize,
    bx: usize,
    by: usize,
) -> impl Printable {
    let mut total = n * m;
    if ax != bx || ay != by {
        total -= r * c;
    }

    let mut ans = 1;
    while total > 0 {
        if total & 1 != 0 {
            ans = (ans * k) % MOD;
        }
        k = (k * k) % MOD;
        total >>= 1;
    }

    ans
}
