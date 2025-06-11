// core logic only
// submission: https://codeforces.com/contest/1615/submission/265756548
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, a: String, b: String) -> impl Printable {
    let (mut cnta, mut cntb) = (0, 0);
    let mut diff = 0;
    for (a, b) in a.bytes().zip(b.bytes()) {
        cnta += usize::from(a == b'1');
        cntb += usize::from(b == b'1');
        diff += usize::from(a != b);
    }

    let mut ans = usize::MAX;
    if cnta == cntb && diff & 1 == 0 {
        ans = ans.min(diff);
    }
    if 1 + n - cnta == cntb && (n - diff) & 1 != 0 {
        ans = ans.min(n - diff);
    }
    if ans == usize::MAX {
        Err(-1)
    } else {
        Ok(ans)
    }
}
