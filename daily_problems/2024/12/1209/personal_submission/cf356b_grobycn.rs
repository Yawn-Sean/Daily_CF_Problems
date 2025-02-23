//! core logic only
//! submission: https://codeforces.com/problemset/submission/356/295766605
const MULTIPLE_TEST: bool = false;

fn gcd(mut a: usize, mut b: usize) -> usize {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}

fn solver(n: usize, m: usize, x: String, y: String) -> impl Printable {
    let (xl, yl) = (x.len(), y.len());
    let (x, y) = (x.as_bytes(), y.as_bytes());
    let g = gcd(xl, yl);
    let mut ans = 0;
    for i in 0..g {
        let mut count = std::collections::HashMap::new();
        for j in (i..yl).step_by(g) {
            *count.entry(y[j]).or_insert(0) += 1;
        }
        for j in (i..xl).step_by(g) {
            ans += *count.get(&x[j]).unwrap_or(&0);
        }
    }
    n * xl - gcd(n, m) * ans
}
