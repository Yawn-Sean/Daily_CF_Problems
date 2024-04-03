// core logic only
// submission: https://codeforces.com/problemset/submission/457/254829330
const MULTIPLE_TEST: bool = false;

fn solver(mut a: String, mut b: String) -> impl Printable {
    use std::iter::repeat;
    let mut rev = false;
    if a.len() < b.len() {
        rev = true;
        std::mem::swap(&mut a, &mut b);
    }
    let d = a.len() - b.len();
    let a = a.bytes().chain(repeat(b'0').take(5));
    let b = repeat(b'0')
        .take(d)
        .chain(b.bytes())
        .chain(repeat(b'0').take(5));

    let (mut d0, mut d1) = (0, 0);
    for (a, b) in a.zip(b) {
        let (a, b) = ((a - b'0') as i64, (b - b'0') as i64);
        let d = a + d0 - b;
        d0 = d1 + d;
        d1 = d;
        if d0 >= 2 && d0 + d1 >= 3 {
            return if rev { "<" } else { ">" };
        }
        if d0 <= -2 && d0 + d1 <= -3 {
            return if rev { ">" } else { "<" };
        }
    }
    "="
}
