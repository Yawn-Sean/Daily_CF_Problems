// core logic only
// submission: https://codeforces.com/problemset/submission/1671/263506555
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, x: i64, scanner: &mut Scanner) -> impl Printable {
    let (mut mn, mut mx) = (i64::MAX, i64::MIN);
    let mut ans = 0;
    let [mut first, mut last] = [i64::MIN; 2];
    for x in scanner.iter::<i64>(n) {
        if last != i64::MIN {
            ans += (x - last).abs();
        } else {
            first = x;
        }
        mn = mn.min(x);
        mx = mx.max(x);
        last = x;
    }
    let d1 = (2 * (mn - 1)).min(first - 1).min(last - 1);
    let d2 = (2 * (x - mx).max(0))
        .min((x - first).abs())
        .min((x - last).abs());
    ans + d1 + d2
}
