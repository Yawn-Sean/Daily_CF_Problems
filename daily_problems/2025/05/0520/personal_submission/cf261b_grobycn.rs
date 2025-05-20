//! core logic only
//! submission: https://codeforces.com/problemset/submission/261/320527553
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<usize>, p: usize) -> impl Printable {
    let n = a.len();
    if a.iter().sum::<usize>() <= p {
        return n as f64;
    }

    let mut fac = [0.0; 51];
    fac[0] = 1.0;
    for i in 1..=50 {
        fac[i] = fac[i - 1] * (i as f64);
    }

    let mut ans = 0.0;
    for (i, &ai) in a.iter().enumerate() {
        let mut dp = vec![vec![0.0; p + 1]; n + 1];
        dp[0][0] = 1.0;
        for (j, &aj) in a.iter().enumerate() {
            if i == j || aj > p {
                continue;
            }
            for c in (0..=j).rev() {
                for w in 0..=p - aj {
                    dp[c + 1][w + aj] += dp[c][w];
                }
            }
        }
        for c in 0..n {
            for w in p.saturating_sub(ai) + 1..=p {
                ans += fac[c] * fac[n - 1 - c] * dp[c][w] * (c as f64);
            }
        }
    }
    ans / fac[n]
}
