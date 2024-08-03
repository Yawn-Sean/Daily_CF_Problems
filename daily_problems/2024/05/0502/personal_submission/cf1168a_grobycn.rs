// core logic only
// submission: https://codeforces.com/contest/1168/submission/259087850
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let check = |op: usize| {
        let mut prev = 0;
        for &x in &a {
            let y = (x + op) % m;
            match (y >= x, y < prev) {
                (true, true) => return false,
                (true, false) | (false, true) => prev = prev.max(x),
                _ => {}
            }
        }
        true
    };

    let (mut lo, mut hi) = (0, m - 1);
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        if check(mid) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    hi
}
