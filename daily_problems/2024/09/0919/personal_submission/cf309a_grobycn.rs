//! core logic only
//! submission: https://codeforces.com/problemset/submission/309/281869520
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, l: usize, t: usize, scanner: &mut Scanner) -> impl Printable {
    let mut a = Vec::with_capacity(n * 2);
    for ai in scanner.iter::<usize>(n) {
        a.push(ai);
    }
    for i in 0..n {
        a.push(a[i] + l);
    }
    let mut ans = 2 * t / l * (n - 1) * n;
    let r = (2 * t) % l;
    for (i, ai) in a.iter().enumerate().take(n) {
        let end = ai + r;
        ans += a[i + 1..i + n].partition_point(|&x| x <= end);
    }
    (ans as f64) / 4.0
}
