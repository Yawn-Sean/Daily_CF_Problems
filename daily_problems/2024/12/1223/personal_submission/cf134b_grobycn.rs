//! core logic only
//! submission: https://codeforces.com/problemset/submission/134/298067643
const MULTIPLE_TEST: bool = false;

fn solver(n: usize) -> impl Printable {
    fn steps(a: usize, b: usize) -> Option<usize> {
        if a == 0 {
            return None;
        }
        if a == 1 {
            return Some(b - 1);
        }
        steps(b % a, a).map(|s| s + b / a)
    }
    (1..=n).filter_map(|i| steps(i, n)).min().unwrap()
}
