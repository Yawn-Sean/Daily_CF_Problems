// core logic only
// submission: https://codeforces.com/problemset/submission/533/262026931
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, s: String, t: String) -> impl Printable {
    let pre = s
        .bytes()
        .zip(t.bytes())
        .take_while(|&(si, ti)| si == ti)
        .count();
    let suf = s
        .bytes()
        .rev()
        .zip(t.bytes().rev())
        .take_while(|&(si, ti)| si == ti)
        .count();
    let (s, t) = (&s[pre..n - suf], &t[pre..n - suf]);
    let mut ans = 0;
    if s[1..] == t[..t.len() - 1] {
        ans += 1;
    }
    if s[..s.len() - 1] == t[1..] {
        ans += 1;
    }
    ans
}
