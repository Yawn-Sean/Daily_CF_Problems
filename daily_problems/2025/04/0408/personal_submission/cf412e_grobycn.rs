//! core logic only
//! submission: https://codeforces.com/problemset/submission/412/314500138
const MULTIPLE_TEST: bool = false;

fn solver(s: String) -> impl Printable {
    let mut ans = 0;
    let mut p = "";
    for t in s.split('@') {
        if !p.is_empty() && !t.is_empty() {
            let n = t.bytes().take_while(u8::is_ascii_alphanumeric).count();
            if n > 0 {
                if let Some(b'.') = t.as_bytes().get(n) {
                    let c = t[n + 1..]
                        .bytes()
                        .take_while(u8::is_ascii_alphabetic)
                        .count();
                    if c > 0 {
                        ans += c * p
                            .bytes()
                            .rev()
                            .take_while(|&b| b.is_ascii_alphanumeric() || b == b'_')
                            .filter(u8::is_ascii_alphabetic)
                            .count();
                    }
                }
            }
        }
        p = t;
    }
    ans
}
