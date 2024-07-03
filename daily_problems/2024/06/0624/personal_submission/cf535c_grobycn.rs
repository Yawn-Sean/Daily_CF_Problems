// core logic only
// submission: https://codeforces.com/problemset/submission/535/267188250
const MULTIPLE_TEST: bool = false;

fn solver(a: usize, b: usize, n: usize, scanner: &mut Scanner) -> impl Printable {
    // s_i = a + (i - 1) \times b
    // sum_{i = l}^r s_i <= t \times m
    // s_r <= t
    let ans: Vec<_> = scanner
        .iter::<(usize, usize, usize)>(n)
        .map(|(l, t, m)| {
            if t < a {
                return Err(-1);
            }
            let sl = a + (l - 1) * b;
            let (mut lo, mut hi) = (l, (t - a) / b + 10);
            while lo < hi {
                let mid = (hi - lo) / 2 + lo;
                let sr = a + (mid - 1) * b;
                let sum = (sl + sr) * (mid + 1 - l) / 2;
                if sr > t || sum > t * m {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            if hi <= l {
                Err(-1)
            } else {
                Ok(hi - 1)
            }
        })
        .collect();
    Sep::<_, '\n'>(ans)
}
