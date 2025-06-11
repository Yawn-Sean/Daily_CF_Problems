//! core logic only
//! submission: https://codeforces.com/problemset/submission/593/317329723
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    // strategy:
    // use f(t) = (1 - |t - i|) + |1 - |t - i||
    // for |t - i| >= 1, f(t) = 0
    //     |t - i| < 1,  f(t) = 2 - 2 |t - i|
    // shape like: --^--
    // max(f(t)) = f(i) = 2

    let func = |i: i64, mx: i64| {
        let c = mx >> 1;
        format!("({c}*((1-abs((t-{i})))+abs((1-abs((t-{i}))))))")
    };
    let mut f = String::from("0");
    let mut g = String::from("0");
    for ((x, y, _), i) in scanner.iter::<(i64, i64, i64)>(n).zip(1..) {
        f = format!("({}+{})", f, func(i, x));
        g = format!("({}+{})", g, func(i, y));
    }
    f.cr().then(g)
}
