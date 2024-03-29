// core logic only
// submission: https://codeforces.com/problemset/submission/1163/253640945
const MULTIPLE_TEST: bool = false;

fn solver(c: String, s: String, t: String) -> impl Printable {
    fn longest_prefix_suffix(s: &[u8]) -> Vec<usize> {
        let n = s.len();
        let mut lps = vec![0; n];
        let mut l = 0;
        for (&b, i) in s[1..].iter().zip(1..) {
            while b != s[l] && l > 0 {
                l = lps[l - 1];
            }
            if b == s[l] {
                l += 1;
                lps[i] = l;
            }
        }
        lps
    }
    fn next(s: &[u8]) -> Vec<[usize; 26]> {
        let n = s.len();
        let mut nxt = vec![[0; 26]; n + 1];
        let lps = longest_prefix_suffix(s);

        for matched in 0..=n {
            for (i, b) in (b'a'..=b'z').enumerate() {
                let mut l = matched;
                while l == n || (l > 0 && s[l] != b) {
                    l = lps[l - 1];
                }
                if s[l] == b {
                    l += 1;
                }
                nxt[matched][i] = l;
            }
        }
        nxt
    }

    let (s, t) = (s.as_bytes(), t.as_bytes());
    let (n, m) = (s.len(), t.len());
    let nxts = next(s);
    let nxtt = next(t);

    let mut dp = vec![vec![i64::MIN / 2; m + 1]; n + 1];
    dp[0][0] = 0;

    for b in c.bytes() {
        let mut dp1 = vec![vec![i64::MIN / 2; m + 1]; n + 1];
        let idx = (b - b'a') as usize;
        let range = if b == b'*' { 0..=25 } else { idx..=idx };
        for i in 0..=n {
            for j in 0..=m {
                for k in range.clone() {
                    let ni = nxts[i][k];
                    let nj = nxtt[j][k];
                    dp1[ni][nj] = dp1[ni][nj].max(dp[i][j]);
                }
            }
        }
        dp = dp1;
        (0..=n).for_each(|i| dp[i][m] -= 1);
        (0..=m).for_each(|i| dp[n][i] += 1);
    }

    *dp.iter().map(|row| row.iter()).flatten().max().unwrap()
}
