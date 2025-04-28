//! core logic only
//! submission: https://codeforces.com/problemset/submission/1599/308080607
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, p: f64) -> impl Printable {
    let tot = (n * (n - 1) * (n - 2) / 6) as f64;
    for x in 0..n {
        let mut prob = ((x * (n - x) * (n - x - 1)) as f64) / 4.0;
        prob += (x * x.saturating_sub(1) / 2 * (n - x)) as f64;
        prob += (x * x.saturating_sub(1) * x.saturating_sub(2) / 6) as f64;
        if prob / tot >= p {
            return x;
        }
    }
    n
}
