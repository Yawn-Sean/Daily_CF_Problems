//! core logic only
//! submission: https://codeforces.com/problemset/submission/1089/312208254
const MULTIPLE_TEST: bool = false;

fn solver(n: usize) -> impl Printable {
    for mut x in 2.. {
        if x * x >= n {
            break;
        }
        if n % x == 0 {
            let mut y = n / x;
            while y % x == 0 {
                y /= x;
            }
            if y == 1 {
                break;
            }
            x = n / y;
            if x > y {
                std::mem::swap(&mut x, &mut y);
            }
            // x < y, xy = n, gcd(x, y) = 1
            // ax + by = n - 1 = xy - 1
            // a/y + b/x = 1 - 1/n
            // There must be some b in [1, x) such that by % x = x - 1
            for b in 1..x {
                // And b*y <= (x - 1)y = n - y < n - 1
                let ax = n - 1 - b * y;
                // If b*y % x = x - 1, then ax = n - kx - x = (y - k - 1)x
                if ax % x == 0 {
                    return Ok("YES".cr().then(2).cr().then((ax / x, y)).cr().then((b, x)));
                }
            }
        }
    }
    Err("NO")
}
