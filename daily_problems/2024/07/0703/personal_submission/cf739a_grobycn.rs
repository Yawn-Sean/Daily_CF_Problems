// core logic only
// submission: https://codeforces.com/contest/739/submission/268633394
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mex = scanner
        .iter::<(usize, usize)>(m)
        .map(|(l, r)| r + 1 - l)
        .min()
        .unwrap();
    let arr = (0..n).map(move |i| i % mex);

    mex.cr().then(Sep::<_, ' '>(arr))
}
