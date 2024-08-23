//! core logic only
//! submission: https://codeforces.com/problemset/submission/360/277672472
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<i64> = scanner.iter(n).collect();
    let check = |max: i64| {
        let mut dp = vec![1; n];
        for (i, &xi) in a.iter().enumerate() {
            for (j, &xj) in a[..i].iter().enumerate() {
                if (xi - xj).abs() <= max * ((i - j) as i64) {
                    dp[i] = dp[i].max(dp[j] + 1);
                }
            }
        }
        dp.into_iter().max().unwrap() >= n - k
    };

    let (mut lo, mut hi) = (0, 2_000_000_000);
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
