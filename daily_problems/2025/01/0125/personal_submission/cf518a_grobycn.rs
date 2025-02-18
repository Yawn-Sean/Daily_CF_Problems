//! core logic only
//! submission: https://codeforces.com/problemset/submission/518/302837493
const MULTIPLE_TEST: bool = false;

fn solver(s: String, t: String) -> impl Printable {
    let mut ans = s.into_bytes();
    for b in ans.iter_mut().rev() {
        if *b == b'z' {
            *b = b'a';
        } else {
            *b += 1;
            break;
        }
    }

    if ans.iter().zip(t.bytes()).all(|(&s, t)| s == t) {
        Err("No such string")
    } else {
        Ok(unsafe { String::from_utf8_unchecked(ans) })
    }
}
