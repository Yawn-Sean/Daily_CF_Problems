//! core logic only
//! submission: https://codeforces.com/problemset/submission/1196/268001766
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, k: usize, s: String) -> impl Printable {
    use std::iter::repeat;
    let t: Vec<_> = repeat("RGB".bytes()).flatten().take(n + 2).collect();
    let s = s.as_bytes();
    minop(s, &t[..n], k)
        .min(minop(s, &t[1..=n], k))
        .min(minop(s, &t[2..=n + 1], k))
}

fn minop(s: &[u8], t: &[u8], k: usize) -> usize {
    let mut diff = usize::MAX;
    let mut ans = diff;
    let mut prev = 0;
    for (ws, wt) in s.windows(k).zip(t.windows(k)) {
        if diff == usize::MAX {
            diff = ws.iter().zip(wt).filter(|&(a, b)| a != b).count();
        } else {
            diff += usize::from(ws[k - 1] != wt[k - 1]);
            diff -= prev;
        }
        ans = ans.min(diff);
        prev = usize::from(ws[0] != wt[0]);
    }
    ans
}
