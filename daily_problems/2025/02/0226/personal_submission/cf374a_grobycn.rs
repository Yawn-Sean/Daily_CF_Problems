//! core logic only
//! submission: https://codeforces.com/problemset/submission/374/307924119
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, i: usize, j: usize, a: usize, b: usize) -> impl Printable {
    if (i == 1 || i == n) && (j == 1 || j == m) {
        return Ok(0);
    }
    if n <= a || m <= b {
        return Err("Poor Inna and pony!");
    }
    let moveto = |x: usize, y: usize| {
        let mut dx = x.abs_diff(i);
        if dx % a != 0 {
            return None;
        }
        let mut dy = y.abs_diff(j);
        if dy % b != 0 {
            return None;
        }
        dx /= a;
        dy /= b;
        if dx.abs_diff(dy) & 1 != 0 {
            return None;
        }
        Some(dx.max(dy))
    };
    [(1, 1), (1, m), (n, 1), (n, m)]
        .iter()
        .filter_map(|&(x, y)| moveto(x, y))
        .min()
        .ok_or("Poor Inna and pony!")
}
