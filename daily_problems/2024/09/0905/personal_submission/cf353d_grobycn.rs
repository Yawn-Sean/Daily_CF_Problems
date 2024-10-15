//! core logic only
//! submission: https://codeforces.com/problemset/submission/353/279956551
const MULTIPLE_TEST: bool = false;

fn solver(s: String) -> impl Printable {
    let mut target = 0;
    let mut ans = 0;
    for (i, c) in s.chars().enumerate() {
        if c == 'F' {
            if i != target {
                ans = (ans + 1).max(i - target);
            }
            target += 1;
        }
    }
    ans
}
