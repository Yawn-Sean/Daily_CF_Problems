// core logic only
// submission: https://codeforces.com/contest/1168/submission/263028107
const MULTIPLE_TEST: bool = false;

fn check(s: &[u8]) -> bool {
    let n = s.len();
    if n < 3 {
        return false;
    }
    for x in 0..n - 2 {
        for k in 1.. {
            if x + 2 * k >= n {
                break;
            }
            if s[x] == s[x + k] && s[x] == s[x + 2 * k] {
                return true;
            }
        }
    }
    false
}

fn solver(s: String) -> impl Printable {
    let s = s.as_bytes();
    let n = s.len();
    let mut r = 0;
    let mut ans = 0;
    for l in 0..n {
        while r < n && !check(&s[l..=r]) {
            r += 1;
        }
        ans += n - r;
    }
    ans
}
