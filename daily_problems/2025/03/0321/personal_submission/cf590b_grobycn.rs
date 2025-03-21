//! core logic only
//! submission: https://codeforces.com/problemset/submission/590/311653721
const MULTIPLE_TEST: bool = false;

fn solver(
    x1: f64,
    y1: f64,
    x2: f64,
    y2: f64,
    vmax: f64,
    t: f64,
    vx: f64,
    vy: f64,
    wx: f64,
    wy: f64,
) -> impl Printable {
    let (xtp, ytp) = (x2 - t * vx, y2 - t * vy);
    let check = |tm: f64| {
        let (x, y) = if tm <= t {
            (x2 - tm * vx, y2 - tm * vy)
        } else {
            (xtp - (tm - t) * wx, ytp - (tm - t) * wy)
        };
        let d = ((x - x1) * (x - x1) + (y - y1) * (y - y1)).sqrt();
        d / vmax <= tm
    };

    let (mut lo, mut hi) = (0.0, 1_000_000_000.0);
    for _ in 0..100 {
        let mid = (hi + lo) / 2.0;
        if check(mid) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    hi
}
