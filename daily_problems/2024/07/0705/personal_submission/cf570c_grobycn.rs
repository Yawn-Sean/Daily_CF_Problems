// core logic only
// submission: https://codeforces.com/contest/570/submission/268943235
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, s: String, scanner: &mut Scanner) -> impl Printable {
    let mut seg_cnt = 0;
    let mut dot_cnt = 0;
    for seg in s.split(|c| c != '.') {
        if seg.is_empty() {
            continue;
        }
        seg_cnt += 1;
        dot_cnt += seg.len();
    }
    let mut s = s.into_bytes();
    let mut ans = Vec::with_capacity(m);
    for (mut i, c) in scanner.iter::<(usize, char)>(m) {
        let b = c as u8;
        i -= 1;
        if (s[i] == b'.') ^ (b == b'.') {
            if b == b'.' {
                dot_cnt += 1;
                if (i > 0 && s[i - 1] == b'.') && (i + 1 < n && s[i + 1] == b'.') {
                    seg_cnt -= 1;
                }
                if (i == 0 || s[i - 1] != b'.') && (i + 1 == n || s[i + 1] != b'.') {
                    seg_cnt += 1;
                }
            } else {
                dot_cnt -= 1;
                if (i > 0 && s[i - 1] == b'.') && (i + 1 < n && s[i + 1] == b'.') {
                    seg_cnt += 1;
                }
                if (i == 0 || s[i - 1] != b'.') && (i + 1 == n || s[i + 1] != b'.') {
                    seg_cnt -= 1;
                }
            }
        }
        ans.push(dot_cnt - seg_cnt);
        s[i] = c as u8;
    }
    Sep::<_, '\n'>(ans)
}
