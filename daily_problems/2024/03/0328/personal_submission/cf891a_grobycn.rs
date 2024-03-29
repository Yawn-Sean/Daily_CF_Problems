// core logic ony
// submission: https://codeforces.com/problemset/submission/891/253637510
const MULTIPLE_TEST: bool = false;

fn solver(xs: Vec<usize>) -> impl Printable {
    fn gcd(mut a: usize, mut b: usize) -> usize {
        while b != 0 {
            let t = b;
            b = a % b;
            a = t;
        }
        a
    }

    let n = xs.len();
    let ones = xs.iter().filter(|&&x| x == 1).count();
    if ones > 0 {
        return Ok(n - ones);
    }

    let mut mn = usize::MAX;
    for (i, &x) in xs.iter().enumerate() {
        let mut g = x;
        for (&y, l) in xs[i + 1..].iter().zip(2..) {
            g = gcd(y, g);
            if g == 1 {
                mn = mn.min(l);
                break;
            }
        }
    }
    if mn == usize::MAX {
        Err(-1)
    } else {
        Ok(n + mn - 2)
    }
}
