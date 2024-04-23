// core logic only
// submission: https://codeforces.com/problemset/submission/922/257861436
const MULTIPLE_TEST: bool = false;

fn solver(ts: Vec<String>) -> impl Printable {
    let scnt: Vec<_> = ts
        .iter()
        .map(|t| t.bytes().filter(|&b| b == b's').count())
        .collect();
    let mut indices: Vec<_> = (0..ts.len()).collect();
    indices.sort_unstable_by(|&i, &j| {
        let (scnti, scntj) = (scnt[i], scnt[j]);
        let (hcnti, hcntj) = (ts[i].len() - scnti, ts[j].len() - scntj);
        (scntj * hcnti).cmp(&(scnti * hcntj))
    });
    let mut s = 0;
    let mut ans = 0usize;
    for b in indices.iter().map(|&i| ts[i].bytes()).flatten() {
        if b == b's' {
            s += 1;
        } else {
            ans += s;
        }
    }
    ans
}
