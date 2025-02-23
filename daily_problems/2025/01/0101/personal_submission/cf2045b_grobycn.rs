//! core logic only
//! submission: https://codeforces.com/problemset/submission/2045/299263832
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, d: usize, s: usize) -> impl Printable {
    if d < s {
        return s;
    }
    let (n, d) = (n / s, d / s);
    if 2 * d <= n {
        return 2 * d * s;
    }
    if n <= d + 1 {
        return n * s;
    }
    if n & 1 == 0 {
        return n * s;
    }
    let mut x = 2;
    while x * x <= n && n - n / x <= d {
        if n % x == 0 {
            // 1 -> n / x -> n
            return n * s;
        }
        x += 1;
    }
    (n - 1) * s
}
