//! core logic only
//! submission: https://codeforces.com/problemset/submission/1090/296168497
const MULTIPLE_TEST: bool = true;

fn solver(
    n: usize,
    l: i64,
    r: i64,
    x: u64,
    y: u64,
    z: u64,
    mut b1: u64,
    mut b2: u64,
) -> impl Printable {
    let mut a = vec![0; n];
    let len = r + 1 - l;
    a[0] = (b1 as i64) % len + l;
    a[1] = (b2 as i64) % len + l;
    let m = 1 << 32;
    let (mut ans, mut mn) = if a[0] < a[1] {
        (a[0] * a[1], a[0])
    } else {
        (i64::MAX, a[1])
    };

    for i in 2..n {
        let b = (((b1 * x) % m + b2 * y) % m + z) % m;
        a[i] = (b as i64) % len + l;
        (b1, b2) = (b2, b);
        if mn < a[i] {
            ans = ans.min(mn * a[i]);
        } else {
            mn = a[i];
        }
    }

    let mut mx = i64::MIN;
    for &x in a.iter().rev() {
        if mx > x {
            ans = ans.min(mx * x);
        } else {
            mx = x;
        }
    }
    if ans == i64::MAX {
        Err("IMPOSSIBLE")
    } else {
        Ok(ans)
    }
}
