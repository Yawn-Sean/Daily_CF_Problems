//! core logic only
//! submission: https://codeforces.com/contest/1600/submission/277348773
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<u32>) -> impl Printable {
    let l = a.windows(2).take_while(|w| w[0] < w[1]).count() + 1;
    let r = a.windows(2).rev().take_while(|w| w[0] > w[1]).count() + 1;
    if (l | r) & 1 == 0 {
        "Bob"
    } else {
        "Alice"
    }
}
