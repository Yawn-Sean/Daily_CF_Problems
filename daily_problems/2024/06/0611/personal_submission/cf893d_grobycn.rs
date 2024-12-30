// core logic only
// submission: https://codeforces.com/problemset/submission/893/265207358
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, d: i64, scanner: &mut Scanner) -> impl Printable {
    let (mut mn, mut mx) = (0, 0);
    let mut ans = 0;
    for x in scanner.iter::<i64>(n) {
        if x == 0 {
            if mx < 0 {
                ans += 1;
                mn = 0;
                mx = d;
            } else if mn < 0 {
                mn = 0;
            }
        } else {
            mn += x;
            if mn > d {
                return -1;
            }
            mx = (mx + x).min(d);
        }
    }
    ans
}
