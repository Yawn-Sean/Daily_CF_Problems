//! core logic only
//! submission: https://codeforces.com/problemset/submission/1912/302040296
const MULTIPLE_TEST: bool = true;

fn solver(b: usize, n: usize) -> impl Printable {
    let mut pow = b;
    for k in 1..=n {
        match pow % n {
            0 => return Ok((1, k)),
            1 => return Ok((2, k)),
            x if x + 1 == n => return Ok((3, k)),
            _ => pow = (pow * b) % n,
        }
    }
    Err(0)
}
