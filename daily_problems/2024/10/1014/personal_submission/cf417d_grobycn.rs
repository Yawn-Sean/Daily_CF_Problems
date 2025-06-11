//! core logic only
//! submission: https://codeforces.com/problemset/submission/417/285833375
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, b: usize, scanner: &mut Scanner) -> impl Printable {
    let mut friends: Vec<(usize, usize, Vec<u8>)> = scanner.iter(n).collect();
    friends.sort_unstable_by_key(|f| f.1);
    let mut dp = vec![usize::MAX / 2; 1 << m];
    dp[0] = 0;
    let mut ans = usize::MAX;
    let mask_all = (1 << m) - 1;
    for (xi, ki, mi) in friends {
        let mi = mi.into_iter().fold(0, |acc, x| acc | (1 << (x - 1)));
        for msk in (0..=mask_all).rev() {
            dp[mi | msk] = dp[mi | msk].min(dp[msk] + xi);
        }
        ans = ans.min(dp[mask_all] + ki * b);
    }
    if ans >= usize::MAX / 2 {
        return Err(-1);
    }
    Ok(ans)
}
