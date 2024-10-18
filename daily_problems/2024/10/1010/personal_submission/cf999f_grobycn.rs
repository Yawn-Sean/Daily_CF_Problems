//! core logic only
//! submission: https://codeforces.com/problemset/submission/999/285104803
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashMap;
    let mut cards = HashMap::new();
    for ci in scanner.iter::<usize>(n * k) {
        *cards.entry(ci).or_insert(0) += 1;
    }
    let mut fav_cnt = HashMap::new();
    for fi in scanner.iter::<usize>(n) {
        *fav_cnt.entry(fi).or_insert(0) += 1;
    }
    let h: Vec<usize> = scanner.iter(k).collect();
    let mut dp = vec![vec![0; n * k + 1]; n + 1];
    for p in 1..=n {
        for c in 0..=p * k {
            let mut mx = dp[p - 1][c];
            for (i, hi) in h.iter().enumerate().take(c) {
                mx = mx.max(dp[p - 1][c - 1 - i] + hi);
            }
            dp[p][c] = mx;
        }
    }
    let mut ans = 0;
    for (fav, &cnt) in &fav_cnt {
        if let Some(&card_cnt) = cards.get(fav) {
            if card_cnt >= cnt * k {
                ans += h[k - 1] * cnt;
            } else {
                ans += dp[cnt][card_cnt];
            }
        }
    }
    ans
}
