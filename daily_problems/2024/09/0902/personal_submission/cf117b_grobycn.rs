//! core logic only
//! submission: https://codeforces.com/problemset/submission/117/279341811
const MULTIPLE_TEST: bool = false;

fn solver(a: usize, b: usize, m: usize) -> impl Printable {
    if b >= m - 1 {
        return Err(2);
    }
    let rem = 1_000_000_000 % m;
    if rem == 0 {
        return Err(2);
    }
    for x in 1..=a.min(m - 1) {
        let rem = (x * rem) % m;
        if rem != 0 && rem + b < m {
            return Ok(1.cr().then(format!("{x:09}")))
        }
    }
    Err(2)
}
