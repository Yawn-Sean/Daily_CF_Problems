//! core logic only
//! submission: https://codeforces.com/problemset/submission/811/287226762
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<usize>) -> impl Printable {
    let n = a.len();
    let mut left = vec![usize::MAX; 5001];
    let mut right = vec![usize::MAX; 5001];
    for (i, &x) in a.iter().enumerate() {
        if left[x] == usize::MAX {
            left[x] = i;
        }
        right[x] = i;
    }

    let mut dp = vec![0; n + 1];
    let mut seen = vec![false; 5001];
    for (mut idx, &x) in a.iter().enumerate() {
        if left[x] == idx {
            let mut i = idx;
            let mut r = right[x];
            let mut xor = 0;
            while i <= r {
                if !seen[a[i]] {
                    if left[a[i]] < idx {
                        break;
                    }
                    seen[a[i]] = true;
                    xor ^= a[i];
                    r = r.max(right[a[i]]);
                }
                i += 1;
            }
            if i == r + 1 {
                dp[i] = dp[i].max(dp[idx] + xor);
            }
            a[idx..i].iter().for_each(|&x| seen[x] = false);
        }
        dp[idx + 1] = dp[idx + 1].max(dp[idx]);
    }

    dp[n]
}
