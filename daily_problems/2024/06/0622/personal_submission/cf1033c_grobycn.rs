// core logic only
// submission: https://codeforces.com/contest/1033/submission/266777658
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<usize>) -> impl Printable {
    let n = a.len();
    let mut pos = vec![0; n];
    let mut ans = vec![0; n];
    for (i, &x) in a.iter().enumerate() {
        pos[x - 1] = i;
    }
    'outer: for v in (1..=n).rev() {
        let i = pos[v - 1];
        for j in (i + v..n).step_by(v) {
            if a[j] > v && ans[j] == b'B' {
                ans[i] = b'A';
                continue 'outer;
            }
        }
        if i >= v {
            for j in (0..=i - v).rev().step_by(v) {
                if a[j] > v && ans[j] == b'B' {
                    ans[i] = b'A';
                    continue 'outer;
                }
            }
        }
        ans[i] = b'B';
    }
    unsafe { String::from_utf8_unchecked(ans) }
}
