//! core logic only
//! submission: https://codeforces.com/problemset/submission/427/303672784
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let xs: Vec<i64> = scanner.iter(n).collect();
    let mut pre: Vec<_> = xs.iter().step_by(m).copied().collect();
    let mut suf: Vec<_> = xs.iter().rev().step_by(m).copied().rev().collect();
    for i in 1..pre.len() {
        pre[i] += pre[i - 1];
    }
    for i in (1..suf.len()).rev() {
        suf[i - 1] += suf[i];
    }

    let mut ans = i64::MAX;
    for (i, &x) in xs.iter().enumerate() {
        let left = (i + m - 1) / m;
        let right = (n - 1 - i + m - 1) / m;
        let mut sum = (left as i64) * x - *pre.get(left.wrapping_sub(1)).unwrap_or(&0);
        sum += *suf.get(suf.len() - right).unwrap_or(&0) - (right as i64) * x;
        ans = ans.min(2 * sum);
    }
    ans
}
