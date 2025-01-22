//! core logic only
//! submission: https://codeforces.com/problemset/submission/305/287699789
const MULTIPLE_TEST: bool = false;

fn solver(mut p: usize, mut q: usize, n: usize, scanner: &mut Scanner) -> impl Printable {
    for ai in scanner.iter::<usize>(n) {
        if p.checked_div(q).unwrap_or(0) < ai {
            return "NO";
        }
        (p, q) = (q, p - ai * q);
    }
    if q == 0 {
        "YES"
    } else {
        "NO"
    }
}
