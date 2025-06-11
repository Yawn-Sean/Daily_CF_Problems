//! core logic only
//! submission: https://codeforces.com/problemset/submission/1260/299168427
const MULTIPLE_TEST: bool = false;

fn solver(m: usize, n: usize, k: usize, t: usize, scanner: &mut Scanner) -> impl Printable {
    let mut soldiers: Vec<usize> = scanner.iter(m).collect();
    soldiers.sort_unstable();
    let mut traps: Vec<(usize, usize, usize)> = scanner.iter(k).collect();
    traps.sort_unstable();
    let check = |c: usize| {
        let min_agility = soldiers[m - c];
        let mut cnt = 0;
        let (mut left, mut right) = (1, 0);
        for &(l, r, d) in &traps {
            if d <= min_agility {
                continue;
            }
            if l <= right {
                right = right.max(r);
            } else {
                cnt += right + 1 - left;
                (left, right) = (l, r);
            }
        }
        cnt += right + 1 - left;
        cnt * 2 + n + 1 <= t
    };

    let (mut lo, mut hi) = (1, m + 1);
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        if check(mid) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    hi - 1
}
