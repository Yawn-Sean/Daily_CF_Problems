//! core logic only
//! submission: https://codeforces.com/problemset/submission/325/284775494
const MULTIPLE_TEST: bool = false;

fn solver(n: usize) -> impl Printable {
    let mut ans = vec![];
    for shift in 0..60 {
        let round = |odd: usize| {
            odd.saturating_mul((1 << shift) - 1)
                .saturating_add(odd * (odd - 1) / 2)
        };

        let check = |odd: usize| round(odd) < n;
        let (mut lo, mut hi) = (1, 2_000_000_000);
        while lo < hi {
            let mid = (hi - lo) / 2 + lo;
            if check(mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if hi & 1 != 0 && round(hi) == n {
            ans.push(hi << shift);
        }
    }
    if ans.is_empty() {
        return Err(-1);
    }
    Ok(Sep::<_, '\n'>(ans))
}
