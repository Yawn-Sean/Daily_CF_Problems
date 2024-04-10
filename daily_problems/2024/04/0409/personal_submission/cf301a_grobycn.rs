// core logic only
// submission: https://codeforces.com/contest/301/submission/255873609
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut neg_cnt = 0;
    let mut sum = 0;
    let mut min = i64::MAX;
    for x in scanner.iter::<i64>(2 * n - 1) {
        if x < 0 {
            neg_cnt += 1;
            sum -= x;
            min = min.min(-x);
        } else {
            sum += x;
            min = min.min(x);
        }
    }
    if neg_cnt % 2 == 0 || n % 2 != 0 {
        sum
    } else {
        sum - 2 * min
    }
}
