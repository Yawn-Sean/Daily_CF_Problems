//! core logic only
//! submission: https://codeforces.com/problemset/submission/281/281871172
const MULTIPLE_TEST: bool = false;

fn solver(x: usize, y: usize, n: usize) -> impl Printable {
    let (mut num, mut den) = (0, 1);
    for b in 1..=n {
        let a = b * x / y;
        if (a * y * den).abs_diff(x * b * den) < (num * b * y).abs_diff(x * b * den) { 
            num = a;
            den = b;
        }
        if ((a + 1) * y * den).abs_diff(x * b * den) < (num * b * y).abs_diff(x * b * den) { 
            num = a + 1;
            den = b;
        }
    }
    format!("{num}/{den}")
}
