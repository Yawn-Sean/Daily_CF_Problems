//! core logic only
//! submission: https://codeforces.com/problemset/submission/575/290238360
const MULTIPLE_TEST: bool = false;

fn solver(_scanner: &mut Scanner) -> impl Printable {
    2000.cr().then(Sep::<_, '\n'>(
        (1..=1000).chain((1..=1000).rev()).map(|x| (x, 1, x, 2)),
    ))
}
