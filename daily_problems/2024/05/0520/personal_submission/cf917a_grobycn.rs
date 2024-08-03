// core logic only
// submission: https://codeforces.com/contest/917/submission/261793350
const MULTIPLE_TEST: bool = false;

fn solver(s: String) -> impl Printable {
    let s = s.into_bytes();
    let n = s.len();
    let mut ans = 0;
    for i in 0..n {
        let mut qcnt = 0i32;
        let mut unclosed = 0;
        let mut closed_by_qmark = 0;
        for &b in &s[i..] {
            match b {
                b'(' => unclosed += 1,
                b')' => {
                    if unclosed > 0 {
                        unclosed -= 1;
                    } else if closed_by_qmark > 0 {
                        closed_by_qmark -= 1;
                        qcnt += 1;
                    } else if qcnt > 0 {
                        qcnt -= 1;
                    } else {
                        break;
                    }
                }
                _ => {
                    if unclosed > 0 {
                        unclosed -= 1;
                        closed_by_qmark += 1;
                    } else {
                        qcnt += 1;
                    }
                }
            }
            if unclosed == 0 && qcnt % 2 == 0 {
                ans += 1;
            }
        }
    }
    ans
}
