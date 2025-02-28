//! core logic only
//! submission: https://codeforces.com/problemset/submission/1090/301116189
const MULTIPLE_TEST: bool = false;

fn solver(t: usize, n: usize, a: usize, b: usize, k: usize) -> impl Printable {
    if k > n {
        return 0;
    }
    let cntb = n / 2;
    let cnta = n - cntb;
    let mut ans = t.min((cnta * a + cntb * b) / k);
    if k > cnta {
        ans = ans.min(cntb * b / (k - cnta));
    }
    if k > cntb {
        ans = ans.min(cnta * a / (k - cntb));
    }
    ans
}
