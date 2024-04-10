// core logic only
// submission: https://codeforces.com/problemset/submission/613/255884533
const MULTIPLE_TEST: bool = false;

fn solver(
    n: usize,
    maxa: usize,
    cf: usize,
    cm: usize,
    mut m: usize,
    scanner: &mut Scanner,
) -> impl Printable {
    let mut a: Vec<usize> = scanner.iter(n).collect();
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_unstable_by_key(|&i| a[i]);
    let mut presum = Vec::with_capacity(n + 1);
    presum.push(0);
    for ai in indices.iter().map(|&i| a[i]) {
        presum.push(*presum.last().unwrap() + ai);
    }
    let sum = |l: usize, r: usize| presum[r] - presum[l];

    if sum(0, n) + m >= maxa * n {
        a.iter_mut().for_each(|x| *x = maxa);
        return (n * cf + maxa * cm).cr().then(Sep::<_, ' '>(a));
    }

    let mut max_force = 0;
    let (mut perfect_cnt, mut min_cnt, mut mina) = (0, 0, 0);

    for (i, ai) in indices.iter().rev().map(|&i| a[i]).enumerate() {
        let (mut lo, mut hi) = (0, n - i);
        while lo < hi {
            let mid = (hi - lo) / 2 + lo;
            if sum(0, mid + 1) + m >= (mid + 1) * a[indices[mid]] {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        let mut min = a[indices[hi - 1]];
        min += (m - (hi * min - sum(0, hi))) / hi;
        let force = i * cf + min * cm;
        if force > max_force {
            max_force = force;
            perfect_cnt = i;
            min_cnt = hi;
            mina = min;
        }
        m = match m.checked_sub(maxa - ai) {
            Some(r) => r,
            _ => break,
        };
    }

    indices[..min_cnt].iter().for_each(|&i| a[i] = mina);
    indices[n - perfect_cnt..].iter().for_each(|&i| a[i] = maxa);
    max_force.cr().then(Sep::<_, ' '>(a))
}
