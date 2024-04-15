// core logic only
// submission: https://codeforces.com/problemset/submission/1201/256665273
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, _m: usize, k: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let (mut left, mut right) = (vec![i64::MAX; n], vec![i64::MIN; n]);
    for (mut r, c) in scanner.iter::<(usize, i64)>(k) {
        r -= 1;
        left[r] = left[r].min(c);
        right[r] = right[r].max(c);
    }
    let mut bs: Vec<i64> = scanner.iter(q).collect();
    bs.sort_unstable();

    let (mut dp, mut pos) = if left[0] == i64::MAX {
        ([0, 0], [1, 1])
    } else {
        (
            [right[0] * 2 - left[0] - 1, right[0] - 1],
            [left[0], right[0]],
        )
    };

    let mut d = 1;
    for r in 1..n {
        if left[r] == i64::MAX {
            d += 1;
        } else {
            let mut ndp = [i64::MAX; 2];
            for (&step, &col) in dp.iter().zip(&pos) {
                let idx = bs.partition_point(|&c| c <= col);
                // try the two nearest safe columns
                for i in idx.saturating_sub(1)..=idx.min(q - 1) {
                    let c = bs[i];
                    // go to (r, c) first
                    let step = step + d + (col - c).abs();
                    // go right then left
                    let dist = step + (c - right[r]).abs() + right[r] - left[r];
                    ndp[0] = ndp[0].min(dist);
                    // go left then right
                    let dist = step + (c - left[r]).abs() + right[r] - left[r];
                    ndp[1] = ndp[1].min(dist);
                }
            }
            pos = [left[r], right[r]];
            d = 1;
            dp = ndp;
        }
    }

    dp[0].min(dp[1])
}
