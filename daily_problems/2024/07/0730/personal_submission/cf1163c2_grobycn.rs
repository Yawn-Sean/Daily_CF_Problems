//! core logic only
//! submission: https://codeforces.com/problemset/submission/1163/273484247
const MULTIPLE_TEST: bool = false;

fn solver(points: Vec<(i32, i32)>) -> impl Printable {
    use std::collections::{HashMap, HashSet};
    let mut count = HashMap::new();
    for (i, &(xi, yi)) in points.iter().enumerate() {
        for &(xj, yj) in &points[..i] {
            let mut dx = xi - xj;
            let mut dy = yi - yj;
            if dx == 0 {
                count.entry((0, 1)).or_insert(HashSet::new()).insert(xi);
            } else if dy == 0 {
                count.entry((1, 0)).or_insert(HashSet::new()).insert(yi);
            } else {
                if dx < 0 {
                    dx = -dx;
                    dy = -dy;
                }
                let g = gcd(dx, dy.abs());
                dx /= g;
                dy /= g;
                count
                    .entry((dx, dy))
                    .or_insert(HashSet::new())
                    .insert(yi * dx - xi * dy);
            }
        }
    }
    let mut excluded = 0;
    let mut lcnt = 0;
    for c in count.values().map(|cs| cs.len()) {
        lcnt += c;
        excluded += c * (c - 1) / 2;
    }
    lcnt * (lcnt - 1) / 2 - excluded
}

fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}


