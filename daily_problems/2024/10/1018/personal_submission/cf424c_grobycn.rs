//! core logic only
//! submission: https://codeforces.com/problemset/submission/424/286557013
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut ans = scanner.iter::<usize>(n).fold(0, |acc, x| acc ^ x);
    let prexor = |x: usize| match x & 0x3 {
        0 => x,
        1 => 1,
        2 => x + 1,
        _ => 0,
    };

    for i in 1..=n {
        let r = n % (i << 1);
        if r < i {
            ans ^= prexor(r);
        } else {
            ans ^= prexor(r - i) ^ prexor(i - 1);
        }
    }
    ans
}
