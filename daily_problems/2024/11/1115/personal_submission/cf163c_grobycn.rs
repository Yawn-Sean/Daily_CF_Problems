//! core logic only
//! submission: https://codeforces.com/problemset/submission/163/291592151
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, mut l: usize, v1: usize, v2: usize, scanner: &mut Scanner) -> impl Printable {
    let mut delta = std::collections::BTreeMap::new();
    let len = l * v2;
    l *= v1 + v2;
    for mut x in scanner.iter::<usize>(n) {
        x *= v1 + v2;
        *delta.entry(x).or_insert(0) += 1;
        if x + len > 2 * l {
            *delta.entry(2 * l).or_insert(0) -= 1;
            *delta.entry(0).or_insert(0) += 1;
            *delta.entry(x + len - 2 * l).or_insert(0) -= 1;
        } else {
            *delta.entry(x + len).or_insert(0) -= 1;
        }
    }
    let mut ans = vec![0; n + 1];
    let mut sum = 0;
    let mut left = 0;
    for (x, d) in delta {
        ans[sum as usize] += x - left;
        sum += d;
        left = x;
    }
    ans[0] = 2 * l - ans[1..].iter().sum::<usize>();
    Sep::<_, '\n'>(ans.into_iter().map(move |x| (x as f64) / ((2 * l) as f64)))
}
