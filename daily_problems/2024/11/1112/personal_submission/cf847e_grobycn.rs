//! core logic only
//! submission: https://codeforces.com/problemset/submission/847/291201264
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, s: String) -> impl Printable {
    let check = |t: usize| {
        let mut uncover = 0;
        let mut first_arterisk = usize::MAX;
        for (i, b) in s.bytes().enumerate() {
            match b {
                b'*' => {
                    if i >= uncover && first_arterisk == usize::MAX {
                        first_arterisk = i;
                    }
                }
                b'P' => {
                    let left = i.saturating_sub(first_arterisk);
                    if left > t {
                        return false;
                    }
                    let right = t.saturating_sub(2 * left).max((t - left) / 2);
                    uncover = i + right + 1;
                    first_arterisk = usize::MAX;
                }
                _ => {}
            }
        }
        first_arterisk == usize::MAX
    };

    let (mut lo, mut hi) = (1, 2 * n);
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        if check(mid) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    hi
}
