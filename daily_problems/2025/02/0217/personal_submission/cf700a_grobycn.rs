//! core logic only
//! submission: https://codeforces.com/problemset/submission/700/306539318
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, l: usize, v1: usize, v2: usize, k: usize) -> impl Printable {
    let g = n.div_ceil(k);
    let d = (((g - 1) * 2 * v2) as f64) / ((v1 + v2) as f64);
    (l as f64) * (d + 1.0) / (d * (v1 as f64) + (v2 as f64))
}
