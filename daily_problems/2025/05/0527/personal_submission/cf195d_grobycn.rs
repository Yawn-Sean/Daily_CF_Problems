//! core logic only
//! submission: https://codeforces.com/problemset/submission/195/321667371
const MULTIPLE_TEST: bool = false;

fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashSet;
    let mut set = HashSet::new();
    for (mut k, mut b) in scanner.iter::<(i64, i64)>(n) {
        if k == 0 {
            continue;
        }
        if k < 0 {
            k = -k;
            b = -b;
        }
        let g = gcd(k, b.abs());
        k /= g;
        b /= g;
        set.insert((k, b));
    }
    set.len()
}
