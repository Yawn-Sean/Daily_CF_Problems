// core logic only
// submission: https://codeforces.com/contest/835/submission/262883086
const MULTIPLE_TEST: bool = false;

fn solver(s: String) -> impl Printable {
    let s = s.as_bytes();
    let n = s.len();
    let mut k = vec![vec![0; n]; n];
    let mut ans = vec![0; n];
    (0..n).for_each(|i| k[i][i] = 1);
    ans[0] += n;

    for len in 2..=n {
        for l in 0..=n - len {
            let r = l + len - 1;
            if s[l] == s[r] && (len == 2 || k[l + 1][r - 1] > 0) {
                let m = (r - 1 - l) / 2 + l;
                k[l][r] = k[l][m] + 1;
                ans[k[l][r] - 1] += 1;
            }
        }
    }
    (1..n).rev().for_each(|i| ans[i - 1] += ans[i]);
    Sep::<_, ' '>(ans)
}
