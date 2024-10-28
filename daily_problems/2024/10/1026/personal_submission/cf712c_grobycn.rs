//! core logic only
//! submission: https://codeforces.com/problemset/submission/712/288093103
const MULTIPLE_TEST: bool = false;

fn solver(x: usize, y: usize) -> impl Printable {
    let (mut len1, mut len2) = (y, 2 * y - 1);
    let mut ans = 3;
    while len2 < x {
        (len1, len2) = (len2, len1 + len2 - 1);
        ans += 1;
    }
    ans
}
