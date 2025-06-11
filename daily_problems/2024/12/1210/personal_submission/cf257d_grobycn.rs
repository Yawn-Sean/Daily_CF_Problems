//! core logic only
//! submission: https://codeforces.com/problemset/submission/257/295905214
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<i64>) -> impl Printable {
    let n = a.len();
    let mut flip = vec![false; n];
    let mut s = a[n - 1];
    let mut ans = vec![b'+'; n];
    for (i, &ai) in a.iter().enumerate().rev().skip(1) {
        if s < ai {
            flip[i + 1] = true;
            s = ai - s;
            ans[i] = b'+';
        } else {
            s -= ai;
            ans[i] = b'-';
        }
    }

    let mut rev = false;
    for (sign, flip) in ans.iter_mut().zip(flip) {
        rev ^= flip;
        if rev {
            *sign = if *sign == b'+' { b'-' } else { b'+' };
        }
    }

    unsafe { String::from_utf8_unchecked(ans) }
}
