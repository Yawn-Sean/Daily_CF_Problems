// core logic only
// submission: https://codeforces.com/problemset/submission/1292/265647650
const MULTIPLE_TEST: bool = false;

fn solver(
    x0: i64,
    y0: i64,
    ax: i64,
    ay: i64,
    bx: i64,
    by: i64,
    xs: i64,
    ys: i64,
    t: i64,
) -> impl Printable {
    let mut points = vec![];
    let (mut x, mut y) = (x0, y0);
    while (x - xs) + (y - ys) <= t {
        points.push((x, y));
        x = ax * x + bx;
        y = ay * y + by;
    }

    let mut ans = 0;
    for (i, &(xi, yi)) in points.iter().enumerate() {
        let d = (xi - xs).abs() + (yi - ys).abs();
        for (j, &(xj, yj)) in points[..=i].iter().enumerate() {
            for (&(xk, yk), k) in points[i..].iter().zip(i..) {
                let mut d = d + (xk - xj) + (yk - yj);
                d += ((xi - xj) + (yi - yj)).min((xk - xi) + (yk - yi));
                if d <= t {
                    ans = ans.max(k + 1 - j);
                }
            }
        }
    }
    ans
}
