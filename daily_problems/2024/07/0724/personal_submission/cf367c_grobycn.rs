//! core logic only
//! submission: https://codeforces.com/problemset/submission/367/272332139
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, mut coupons: Vec<(u32, i64)>) -> impl Printable {
    coupons.sort_unstable_by_key(|c| -c.1);
    coupons.into_iter().enumerate().take_while(|&(i, _)| {
        let edge = i * (i + 1) / 2 + if i & 1 != 0 { (i - 1) / 2 } else { 0 };
        edge < n
    }).map(|(_, (_, w))| w).sum::<i64>()
}
