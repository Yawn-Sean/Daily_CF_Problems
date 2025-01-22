//! core logic only
//! submission: https://codeforces.com/problemset/submission/319/293994728
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(x: String) -> impl Printable {
    let mut cnt = 1;
    let mut ans = 0;
    for b in x.bytes().rev() {
        ans = (ans << 1) % MOD;
        if b == b'1' {
            ans = (ans + cnt * cnt) % MOD;
        }
        cnt = (cnt << 1) % MOD;
    }
    ans
}
