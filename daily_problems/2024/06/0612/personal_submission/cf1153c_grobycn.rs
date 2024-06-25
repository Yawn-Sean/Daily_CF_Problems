// core logic only
// submission: https://codeforces.com/problemset/submission/1153/265486507
const MULTIPLE_TEST: bool = false;

fn solver(mut n: usize, s: String) -> impl Printable {
    if n % 2 != 0 {
        return Err(":(");
    }
    let (mut lpcnt, mut rpcnt) = (0, 0);
    s.bytes().for_each(|b| match b {
        b'(' => lpcnt += 1,
        b')' => rpcnt += 1,
        _ => {}
    });
    let m = n / 2;
    if lpcnt > m || rpcnt > m {
        return Err(":(");
    }

    let mut s = s.into_bytes();
    if s[0] == b')' || s[n - 1] == b'(' {
        return Err(":(");
    }

    lpcnt = m - lpcnt;
    let mut unclosed = 0;
    for (i, b) in s.iter_mut().enumerate() {
        if *b == b'?' {
            if lpcnt > 0 {
                lpcnt -= 1;
                *b = b'(';
            } else {
                *b = b')';
            };
        }
        if *b == b'(' {
            unclosed += 1;
        } else {
            if unclosed == 0 || (unclosed == 1 && i != n - 1) {
                return Err(":(");
            }
            unclosed -= 1;
        }
    }
    Ok(unsafe { String::from_utf8_unchecked(s) })
}
