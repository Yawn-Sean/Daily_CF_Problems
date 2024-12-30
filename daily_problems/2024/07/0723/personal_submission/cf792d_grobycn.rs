//! core logic only
//! submission: https://codeforces.com/problemset/submission/792/272127890
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let mut ans = Vec::with_capacity(q);
    for (mut u, s) in scanner.iter::<(usize, String)>(q) {
        for c in s.chars() {
            let lb = u & !(u - 1);
            match c {
                'L' => {
                    if lb != 1 {
                        u ^= lb ^ (lb >> 1);
                    }
                }
                'R' => {
                    if lb != 1 {
                        u ^= lb >> 1;
                    }
                }
                _ => {
                    if u != (n + 1) / 2 {
                        u ^= lb;
                        u |= lb << 1;
                    }
                }
            }
        }
        ans.push(u);
    }
    Sep::<_, '\n'>(ans)
}
