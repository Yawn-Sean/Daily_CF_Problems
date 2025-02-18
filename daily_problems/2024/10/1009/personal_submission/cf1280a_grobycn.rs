//! core logic only
//! submission: https://codeforces.com/problemset/submission/1280/285032511
const MULTIPLE_TEST: bool = true;
const MOD: usize = 1_000_000_007;

fn solver(x: usize, s: String) -> impl Printable {
    let mut s = s.into_bytes();
    let mut l = 0;
    while l < x && s.len() < x {
        let c = s[l] - b'0';
        l += 1;
        if c > 1 {
            let sr = s[l..].to_vec();
            (1..c).for_each(|_| s.extend(sr.iter().copied()));
        }
    }
    let mut ans = s.len();
    while l < x {
        let c = (s[l] - b'0') as usize;
        l += 1;
        ans += (ans + MOD - l) * (c - 1);
        ans %= MOD;
    }
    ans
}
