// core logic only
// submission: https://codeforces.com/contest/946/submission/255253893
const MULTIPLE_TEST: bool = true;

fn solver(s: String) -> impl Printable {
    let mut mask = s.bytes().fold(0u16, |acc, b| acc ^ (1 << (b - b'0')));
    let mut cnt = mask.count_ones() as usize;
    let mut free = 0;
    for (i, b) in s.bytes().enumerate().rev() {
        let bit = 1 << (b - b'0');
        if mask & bit == 0 {
            cnt += 1;
        } else {
            cnt -= 1;
        }
        mask ^= bit;
        for b in (b'0'..b).rev() {
            let bit = 1 << (b - b'0');
            let cnt = if mask & bit == 0 { cnt + 1 } else { cnt - 1 };
            let mask = mask ^ bit;
            if free >= cnt {
                let mut ans = s.into_bytes();
                ans.truncate(i + 1);
                ans[i] = b;
                ans.extend(std::iter::repeat(b'9').take(free - cnt));
                for b in (b'0'..=b'9').rev() {
                    if mask & (1 << (b - b'0')) != 0 {
                        ans.push(b);
                    }
                }
                if ans[0] == b'0' {
                    ans = ans[1..ans.len() - 1].to_vec();
                }
                return unsafe { String::from_utf8_unchecked(ans) };
            }
        }
        free += 1;
    }
    unreachable!()
}
