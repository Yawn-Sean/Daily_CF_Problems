//! core logic only
//! submission: https://codeforces.com/problemset/submission/713/273005762
const MULTIPLE_TEST: bool = false;

fn solver(n: u32, scanner: &mut Scanner) -> impl Printable {
    let mut ask = |x1: u32, y1: u32, x2: u32, y2: u32| {
        println!("? {x1} {y1} {x2} {y2}");
        u8::from_scanner(scanner)
    };
    fn bsearch<F, C>(mn: u32, mx: u32, mut f: F, check: C) -> u32
    where
        F: FnMut(u32) -> u8,
        C: Fn(u8) -> bool,
    {
        let (mut lo, mut hi) = (mn, mx);
        while lo < hi {
            let mid = (hi - lo) / 2 + lo;
            if check(f(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        hi
    }

    let r2 = bsearch(1, n, |x2| ask(1, 1, x2, n), |fx| fx >= 2);
    let r1 = bsearch(1, n, |x2| ask(1, 1, x2, n), |fx| fx >= 1);
    let l2 = bsearch(1, n + 1, |x1| ask(x1, 1, n, n), |fx| fx < 2) - 1;
    let l1 = bsearch(1, n + 1, |x1| ask(x1, 1, n, n), |fx| fx < 1) - 1;
    let u2 = bsearch(1, n, |y2| ask(1, 1, n, y2), |fx| fx >= 2);
    let u1 = bsearch(1, n, |y2| ask(1, 1, n, y2), |fx| fx >= 1);
    let d2 = bsearch(1, n + 1, |y1| ask(1, y1, n, n), |fx| fx < 2) - 1;
    let d1 = bsearch(1, n + 1, |y1| ask(1, y1, n, n), |fx| fx < 1) - 1;

    if l1 == l2 && r1 == r2 {
        return ('!', l1, d2, r1, u1, l1, d1, r1, u2);
    }
    if d1 == d2 && u1 == u2 {
        return ('!', l2, d1, r1, u1, l1, d1, r2, u1);
    }

    let hline = [[(l2, r1), (l1, r2)], [(l1, r1), (l2, r2)]];
    let vline = [[(d2, u1), (d1, u2)], [(d1, u1), (d2, u2)]];
    for h in hline {
        let (x11, x12) = h[0];
        let (x21, x22) = h[1];
        if x11 > x12 || x21 > x22 {
            continue;
        }
        for v in vline {
            for j in 0..2 {
                let (y11, y12) = v[j];
                let (y21, y22) = v[1 - j];
                if y11 > y12 || y21 > y22 {
                    continue;
                }
                if ask(x11, y11, x12, y12) == 1 && ask(x21, y21, x22, y22) == 1 {
                    return ('!', x11, y11, x12, y12, x21, y21, x22, y22);
                }
            }
        }
    }
    unreachable!()
}
