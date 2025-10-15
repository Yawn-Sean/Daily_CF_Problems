//! core logic only
//! submission: https://codeforces.com/problemset/submission/1689/307537391
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let [mut pp, mut pm, mut mp, mut mm] = [i32::MIN; 4];
    for (r, row) in scanner.iter::<String>(n).enumerate() {
        for (c, b) in row.bytes().enumerate() {
            if b == b'B' {
                let (r, c) = (r as i32, c as i32);
                pp = pp.max(r + c);
                pm = pm.max(r - c);
                mp = mp.max(c - r);
                mm = mm.max(-r - c);
            }
        }
    }
    let mut mn = i32::MAX;
    let mut ans = (0, 0);
    for r in 0..n as i32 {
        for c in 0..m as i32 {
            let mx = (pp - r - c).max(pm - r + c).max(mp + r - c).max(mm + r + c);
            if mx < mn {
                mn = mx;
                ans = (r + 1, c + 1);
            }
        }
    }
    ans
}
