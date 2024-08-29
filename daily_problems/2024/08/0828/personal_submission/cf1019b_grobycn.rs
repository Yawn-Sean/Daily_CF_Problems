//! core logic only
//! submission: https://codeforces.com/problemset/submission/1019/278522324
const MULTIPLE_TEST: bool = false;

fn solver(n: i32, scanner: &mut Scanner) -> impl Printable {
    let m = n / 2;
    if m & 1 != 0 {
        return ('!', -1);
    }

    let mut ask = |i: i32| {
        println!("? {i}");
        i64::from_scanner(scanner)
    };

    let a1 = ask(1);
    let a1p = ask(1 + m);
    if a1 == a1p {
        return ('!', 1);
    }
    let d1 = a1p - a1;
    let (mut lo, mut hi) = (2, m);
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        let d = ask(mid + m) - ask(mid);
        if d == 0 {
            return ('!', mid);
        } else if d * d1 > 0 {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    ('!', hi)
}
