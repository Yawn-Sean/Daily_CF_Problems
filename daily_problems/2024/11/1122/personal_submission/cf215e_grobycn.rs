//! core logic only
//! submission: https://codeforces.com/problemset/submission/215/292757028
const MULTIPLE_TEST: bool = false;

fn solver(l: usize, r: usize) -> impl Printable {
    fn count_periodic(max: usize) -> usize {
        let n = 64 - max.leading_zeros() as usize;
        let mut ans = 0;
        for width in 1..=n {
            let mut count = vec![0; width];
            for k in 1..width {
                let cnt: usize = if width == n {
                    max / (((1 << n) - 1) / ((1 << k) - 1)) + 1
                } else {
                    1 << k
                };
                if width % k == 0 {
                    count[k] += cnt.saturating_sub(1 << (k - 1));
                }
            }
            for k in 1..width {
                if width % k != 0 {
                    continue;
                }
                ans += count[k];
                for i in (2 * k..width).step_by(k) {
                    if width % i != 0 {
                        continue;
                    }
                    count[i] -= count[k];
                }
            }
        }
        ans
    }
    count_periodic(r) - count_periodic(l - 1)
}
