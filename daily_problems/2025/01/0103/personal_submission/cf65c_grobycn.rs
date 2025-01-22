//! core logic only
//! submission: https://codeforces.com/problemset/submission/65/299481915
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let ps: Vec<(f64, f64, f64)> = scanner.iter(n + 1).collect();
    let (vp, vs) = <(f64, f64)>::from_scanner(scanner);
    let (px, py, pz) = <(f64, f64, f64)>::from_scanner(scanner);

    let mut acc = 0.0;
    for w in ps.windows(2) {
        let (x0, y0, z0) = w[0];
        let (x1, y1, z1) = w[1];

        let ds = dist((x0, y0, z0), (x1, y1, z1));
        let dp = dist((x1, y1, z1), (px, py, pz));
        if acc + ds / vs >= dp / vp {
            let (mut lo, mut hi) = (0.0, 1.0);
            for _ in 0..100 {
                let mid = (hi + lo) / 2.0;
                let x = x0 + (x1 - x0) * mid;
                let y = y0 + (y1 - y0) * mid;
                let z = z0 + (z1 - z0) * mid;
                let ds = ds * mid;
                let dp = dist((x, y, z), (px, py, pz));
                if acc + ds / vs >= dp / vp {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            let ratio = (hi + lo) / 2.0;
            let x = x0 + (x1 - x0) * ratio;
            let y = y0 + (y1 - y0) * ratio;
            let z = z0 + (z1 - z0) * ratio;
            let t = acc + ds * ratio / vs;
            return Ok("YES".cr().then(t).cr().then((x, y, z)));
        }
        acc += ds / vs;
    }
    Err("NO")
}

fn dist((x0, y0, z0): (f64, f64, f64), (x1, y1, z1): (f64, f64, f64)) -> f64 {
    let (dx, dy, dz) = (x0 - x1, y0 - y1, z0 - z1);
    (dx * dx + dy * dy + dz * dz).sqrt()
}
