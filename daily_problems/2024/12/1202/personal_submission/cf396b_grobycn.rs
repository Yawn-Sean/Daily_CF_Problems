//! core logic only
//! submission: https://codeforces.com/problemset/submission/396/294383292
const MULTIPLE_TEST: bool = true;

fn solver(n: usize) -> impl Printable {
    fn is_prime(x: usize) -> bool {
        for i in 2.. {
            if i * i > x {
                break;
            }
            if x % i == 0 {
                return false;
            }
        }
        true
    }

    fn gcd(mut a: usize, mut b: usize) -> usize {
        while b != 0 {
            let t = b;
            b = a % b;
            a = t;
        }
        a
    }

    let mut l = n;
    while !is_prime(l) {
        l -= 1;
    }
    let mut r = n + 1;
    while !is_prime(r) {
        r += 1;
    }
    let num = l * r + 2 * (n + 1) - 2 * (l + r);
    let den = 2 * l * r;
    let g = gcd(num, den);
    format!("{}/{}", num / g, den / g)
}
