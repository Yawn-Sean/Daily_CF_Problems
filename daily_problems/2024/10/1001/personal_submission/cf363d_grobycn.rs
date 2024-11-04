//! core logic only
//! submission: https://codeforces.com/contest/363/submission/283839453
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, a: usize, scanner: &mut Scanner) -> impl Printable {
    let mut b: Vec<usize> = scanner.iter(n).collect();
    let mut p: Vec<usize> = scanner.iter(m).collect();
    b.sort_unstable();
    p.sort_unstable();

    let check = |r: usize| {
        let mut shared = a;
        for (&cost, &money) in p.iter().zip(b.iter().rev().take(r).rev()) {
            if cost > money {
                let need = cost - money;
                if shared < need {
                    return false;
                }
                shared -= need;
            }
        }
        true
    };

    let (mut lo, mut hi) = (1, n.min(m) + 1);
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        if check(mid) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    let r = hi - 1;
    if r == 0 {
        return (0, 0);
    }
    let s = p.iter().take(r).sum::<usize>().saturating_sub(a);
    (r, s)
}
