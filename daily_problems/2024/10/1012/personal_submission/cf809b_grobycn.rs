//! core logic only
//! submission: https://codeforces.com/problemset/submission/809/285457363
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, _k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut ask = |x: usize, y: usize| {
        println!("1 {x} {y}");
        String::from_scanner(scanner).starts_with("T")
    };

    fn bsearch(mut lo: usize, mut hi: usize, mut check: impl FnMut(usize) -> bool) -> usize {
        while lo < hi {
            let mid = (hi - lo) / 2 + lo;
            if check(mid) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        hi
    };

    let x = bsearch(1, n, |x| ask(x, x + 1));
    let mut y = bsearch(1, x - 1, |x| ask(x, x + 1));
    if y == 0 || !ask(y, x) {
        y = bsearch(x + 1, n, |x| ask(x, x + 1));
    }
    (2, x, y)
}
