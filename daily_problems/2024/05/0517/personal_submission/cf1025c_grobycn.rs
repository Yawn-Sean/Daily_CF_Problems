// core logic only
// submission: https://codeforces.com/problemset/submission/1025/261320338
const MULTIPLE_TEST: bool = false;

fn solver(s: String) -> impl Printable {
    let mut ans = 0;
    let mut len = 0;
    let mut prev = 0;
    for b in s.bytes().chain(s.bytes()) {
        if b != prev {
            len += 1;
            prev = b;
        } else {
            len = 1;
        }
        ans = ans.max(len);
    }
    ans.min(s.len())
}
