// core logic only
// submission: https://codeforces.com/contest/721/submission/260010498
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, mut k: i64, x: i64, scanner: &mut Scanner) -> impl Printable {
    use std::collections::BinaryHeap;

    let mut a: Vec<i64> = scanner.iter(n).collect();
    let mut mnat = 0;
    let mut mn = i64::MAX;
    let mut neg = false;
    for (i, &ai) in a.iter().enumerate() {
        if ai < 0 {
            neg = !neg;
        }
        let ai = ai.abs();
        if ai < mn {
            mn = ai;
            mnat = i;
        }
    }
    if !neg && mn >= k * x {
        a[mnat] = if a[mnat] > 0 { mn - k * x } else { k * x - mn };
        return Sep::<_, ' '>(a);
    }
    if !neg {
        let c = (mn + x) / x; // c * x >= mn + 1
        k -= c;
        a[mnat] = if a[mnat] >= 0 { mn - c * x } else { c * x - mn };
    }
    let mut hp: BinaryHeap<_> = a.iter().map(|&ai| -ai.abs()).zip(0..).collect();
    for _ in 0..k {
        if let Some((ai, i)) = hp.pop() {
            a[i] = if a[i] >= 0 { -ai + x } else { ai - x };
            hp.push((ai - x, i));
        }
    }
    Sep::<_, ' '>(a)
}
