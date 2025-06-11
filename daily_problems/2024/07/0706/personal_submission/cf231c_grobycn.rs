// core logic only
// submission: https://codeforces.com/contest/231/submission/269002290
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: i64, scanner: &mut Scanner) -> impl Printable {
    let mut a: Vec<i64> = scanner.iter(n).collect();
    a.sort_unstable();

    let mut sum = 0;
    let mut len = 0;
    let mut l = 0;
    let mut max_occur = 0;
    let mut min_elem = i64::MAX;
    for (r, &x) in a.iter().enumerate() {
        sum += x;
        len += 1;
        while len * x > sum + k {
            sum -= a[l];
            l += 1;
            len -= 1;
        }
        if len > max_occur {
            max_occur = len;
            min_elem = x;
        }
    }
    (max_occur, min_elem)
}
