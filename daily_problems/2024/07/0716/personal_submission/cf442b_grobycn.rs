//! core logic only
//! submission: https://codeforces.com/problemset/submission/442/270881074
const MULTIPLE_TEST: bool = false;

fn solver(mut prob: Vec<f64>) -> impl Printable {
    prob.sort_unstable_by(|l, r| r.partial_cmp(l).unwrap());
    let (mut p0, mut p1) = (1.0, 0.0);
    let mut ans = 0.0;
    for p in prob {
        (p0, p1) = (p0 * (1.0 - p), p0 * p + p1 * (1.0 - p));
        ans = p1.max(ans);
    }
    ans
}
