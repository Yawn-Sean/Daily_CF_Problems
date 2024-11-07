//! core logic only
//! submission: https://codeforces.com/problemset/submission/814/290398673
const MULTIPLE_TEST: bool = false;

fn solver(mut dancers: Vec<(i64, i64, i64)>) -> impl Printable {
    let n = dancers.len();
    dancers.sort_unstable_by_key(|d| -d.2);
    let mut depth = vec![0; n];
    for (i, &(xi, yi, ri)) in dancers.iter().enumerate() {
        for (j, &(xj, yj, rj)) in dancers[..i].iter().enumerate().rev() {
            if (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) < (ri + rj) * (ri + rj) {
                depth[i] = depth[j] + 1;
                break;
            }
        }
    }

    let mut ans = 0;
    for (&d, &(_, _, r)) in depth.iter().zip(&dancers) {
        ans += (1 - 2 * ((d - 1).max(0) & 1)) * r * r;
    }
    std::f64::consts::PI * (ans as f64)
}
