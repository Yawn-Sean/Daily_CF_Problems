//! core logic only
//! submission: https://codeforces.com/problemset/submission/1055/279340162
const MULTIPLE_TEST: bool = false;

fn solver(mut la: usize, mut ra: usize, ta: usize, mut lb: usize, mut rb: usize, tb: usize) -> impl Printable {
    fn gcd(mut a: usize, mut b: usize) -> usize {
        while b != 0 {
            let t = b;
            b = a % b;
            a = t;
        }
        a
    }

    let g = gcd(ta, tb);
    if la > lb {
        std::mem::swap(&mut la, &mut lb);
        std::mem::swap(&mut ra, &mut rb);
    }
    let d = lb - la;
    let mut ans = 0;
    for c in d/g..d/g + 2 {
        let la = la + c * g;
        let ra = ra + c * g;
        let overlap = (ra.min(rb) + 1).saturating_sub(la.max(lb));
        ans = ans.max(overlap);
    }
    ans
}
