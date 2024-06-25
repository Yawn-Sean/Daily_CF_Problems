// core logic only
// submission: https://codeforces.com/contest/335/submission/261830667
const MULTIPLE_TEST: bool = false;

fn solver(s: String) -> impl Printable {
    let mut count = [0; 26];
    s.bytes().for_each(|b| count[(b - b'a') as usize] += 1);
    for (&c, b) in count.iter().zip('a'..) {
        if c >= 100 {
            return std::iter::repeat(b).take(100).collect::<String>();
        }
    }
    let s = s.into_bytes();
    let n = s.len();
    let mut dp = vec![vec![0; n]; n];
    (0..n).for_each(|i| dp[i][i] = 1);
    for len in 2..=n {
        for l in 0..=n - len {
            let r = l + len - 1;
            if s[l] == s[r] {
                dp[l][r] = dp[l + 1][r - 1] + 2;
            } else {
                dp[l][r] = dp[l + 1][r].max(dp[l][r - 1]);
            }
        }
    }
    let (mut l, mut r) = (0, n - 1);
    let (mut i, mut j) = (0, dp[l][r] - 1);
    let mut bytes = vec![0; dp[l][r]];
    while l < r {
        if s[l] == s[r] {
            bytes[i] = s[l];
            bytes[j] = s[l];
            l += 1;
            r -= 1;
            i += 1;
            j -= 1;
        } else if dp[l][r] == dp[l + 1][r] {
            l += 1;
        } else {
            r -= 1;
        }
    }
    if l == r {
        bytes[i] = s[l];
    }
    if bytes.len() > 100 {
        bytes = bytes
            .iter()
            .take(50)
            .chain(bytes.iter().take(50).rev())
            .copied()
            .collect::<Vec<_>>();
    }
    unsafe { String::from_utf8_unchecked(bytes) }
}
