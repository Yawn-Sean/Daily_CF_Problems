// core logic only
// submission: https://codeforces.com/problemset/submission/960/263516486
const MULTIPLE_TEST: bool = false;

fn solver(q: usize, scanner: &mut Scanner) -> impl Printable {
    let mut ans = vec![];
    let mut shift = [0; 62];
    for _ in 0..q {
        let (t, x) = <(u8, i64)>::from_scanner(scanner);
        let d = (63 - x.leading_zeros()) as usize;
        let mut len = 1 << d;
        match t {
            1 => {
                let k = i64::from_scanner(scanner) % len;
                shift[d] = (shift[d] + k) % len;
            }
            2 => {
                let mut k = i64::from_scanner(scanner) % len;
                for s in shift[d..62].iter_mut() {
                    *s = (*s + k) % len;
                    k *= 2;
                    len <<= 1;
                }
            }
            _ => {
                let mut idx = (x + shift[d]) % len + len;
                let mut path = Vec::with_capacity(d + 1);
                path.push(x);
                for &s in shift[0..d].iter().rev() {
                    idx >>= 1;
                    len >>= 1;
                    let x = (idx - s) % len + len;
                    path.push(x);
                }
                ans.push(path);
            }
        }
    }
    let ans = ans.into_iter().map(|path| Sep::<_, ' '>(path));
    Sep::<_, '\n'>(ans)
}
