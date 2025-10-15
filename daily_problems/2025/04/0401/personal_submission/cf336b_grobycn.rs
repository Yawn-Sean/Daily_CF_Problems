//! core logic only
//! submission: https://codeforces.com/problemset/submission/336/313731414
const MULTIPLE_TEST: bool = false;

fn solver(m: i64, r: i64) -> impl Printable {
    use std::f64::consts::SQRT_2;
    let sum0 = m * 2;
    let sum1i = 4 * (m - 1);
    let sum1f = SQRT_2 * ((2 * (m - 1)) as f64);
    let sum2i = 2 * (m * m + 1) * (m - 2) - 2 * ((m - 1) * m * (2 * m - 1) / 3 - 2);
    let sum2f = SQRT_2 * ((2 * (m - 1) * (m - 2)) as f64);
    let sum = (sum0 + sum1i + sum2i) as f64 + sum1f + sum2f;
    sum / ((m * m) as f64) * (r as f64)
}
