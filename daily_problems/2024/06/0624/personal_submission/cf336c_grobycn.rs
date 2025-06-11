// core logic only
// submission: https://codeforces.com/problemset/submission/336/267186139
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<usize>) -> impl Printable {
    for v in (0..32).rev() {
        let bit = 1 << v;
        let mut and = usize::MAX;
        let mut cnt = 0;
        for &x in &a {
            if x & bit != 0 {
                and &= x;
                cnt += 1;
            }
        }
        if and & (bit - 1) == 0 {
            let b = a.into_iter().filter(move |&x| x & bit != 0);
            return Ok(cnt.cr().then(Sep::<_, ' '>(b)));
        }
    }
    Err(-1)
}
