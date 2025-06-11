//! core logic only
//! submission: https://codeforces.com/problemset/submission/671/296039646
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut c: Vec<usize> = scanner.iter(n).collect();
    c.sort_unstable();
    let mut presum = vec![0; n + 1];
    for (i, &ci) in c.iter().enumerate() {
        presum[i + 1] = presum[i] + ci;
    }
    let sum = |l: usize, r: usize| presum[r] - presum[l];

    fn partition_point(mut lo: usize, mut hi: usize, pred: impl Fn(usize) -> bool) -> usize {
        while lo < hi {
            let mid = (hi - lo) / 2 + lo;
            if pred(mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        hi
    }

    let mx = 1_000_000_000;
    let min_richest = partition_point(0, mx, |mid| {
        let p = c.partition_point(|&ci| ci <= mid);
        let op = sum(p, n) - (n - p) * mid;
        op > k
    });
    if min_richest < c[0] {
        return if presum[n] % n == 0 { 0 } else { 1 };
    }
    let max_poorest = partition_point(0, mx, |mid| {
        let p = c.partition_point(|&ci| ci < mid);
        let op = p * mid - sum(0, p);
        op <= k
    }) - 1;
    if min_richest > max_poorest {
        return min_richest - max_poorest;
    }
    if presum[n] % n == 0 {
        0
    } else {
        1
    }
}
