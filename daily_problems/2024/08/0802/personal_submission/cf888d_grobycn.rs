//! core logic only
//! submission: https://codeforces.com/problemset/submission/888/274018300
const MULTIPLE_TEST: bool = false;

fn combination(n: usize, k: usize) -> usize {
    let num = (n - k + 1..=n).product::<usize>();
    let den = (1..=k).product::<usize>();
    num / den
}

fn solver(n: usize, k: usize) -> impl Printable {
    match k {
        1 => 1,
        2 => 1 + combination(n, 2),
        3 => 1 + combination(n, 2) + combination(n, 3) * 2,
        _ => 1 + combination(n, 2) + combination(n, 3) * 2 + combination(n, 4) * 9,
    }
}
