//! core logic only
//! submission: https://codeforces.com/problemset/submission/209/295241495
const MULTIPLE_TEST: bool = false;

fn solver(a: usize, b: usize, c: usize) -> impl Printable {
    let mut ans = usize::MAX;
    if a & 1 == b & 1 {
        ans = ans.min(a.max(b));
    }
    if a & 1 == c & 1 {
        ans = ans.min(a.max(c));
    }
    if b & 1 == c & 1 {
        ans = ans.min(b.max(c));
    }
    ans
}
