//! core logic only
//! submission: https://codeforces.com/problemset/submission/342/309985514
const MULTIPLE_TEST: bool = false;

fn solver(r: usize, mut h: usize) -> impl Printable {
    let mut ans = h / r * 2;
    h %= r;
    if h * h * 4 >= r * r * 3 {
        ans += 3;
    } else if h * 2 >= r {
        ans += 2;
    } else {
        ans += 1;
    }
    ans
}
