//! core logic only
//! submission: https://codeforces.com/problemset/submission/946/283841171
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut dp = vec![0; k + 1];
    for s in scanner.iter::<String>(n) {
        let s = s.as_bytes();
        let indices: Vec<_> = (0..m).filter(|&i| s[i] == b'1').collect();
        let mut ndp = vec![usize::MAX; k + 1];
        for skip in 0..=k.min(indices.len()) {
            let attend = indices.len() - skip;
            let mn = if attend == 0 {
                0
            } else {
                indices
                    .windows(attend)
                    .map(|w| w[attend - 1] + 1 - w[0])
                    .min()
                    .unwrap()
            };
            for i in skip..=k {
                ndp[i] = ndp[i].min(dp[i - skip] + mn);
            }
        }
        dp = ndp;
    }
    dp[k]
}
