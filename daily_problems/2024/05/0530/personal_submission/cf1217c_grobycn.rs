// core logic only
// submission: https://codeforces.com/contest/1217/submission/263259753
const MULTIPLE_TEST: bool = true;

fn solver(s: String) -> impl Printable {
    let mut ans = 0;
    let mut cnt0 = 0;
    for (i, b) in s.bytes().enumerate() {
        if b == b'0' {
            cnt0 += 1;
        } else {
            let mut decimal = 0;
            for (b, len) in s[i..].bytes().zip(1..).take(20) {
                decimal = 2 * decimal + ((b - b'0') as usize);
                if decimal - len <= cnt0 {
                    ans += 1;
                }
            }
            cnt0 = 0;
        }
    }
    ans
}
