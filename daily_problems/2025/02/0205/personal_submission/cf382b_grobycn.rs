//! core logic only
//! submission: https://codeforces.com/problemset/submission/382/304553757
const MULTIPLE_TEST: bool = false;

fn solver(a: usize, b: usize, w: usize, x: usize, c: usize) -> impl Printable {
    if c <= a {
        return 0;
    }
    if x * (c - a) <= b {
        return c - a;
    }
    (w * (c - a) - b + w - x - 1) / (w - x)
}
