//! core logic only
//! submission: https://codeforces.com/problemset/submission/818/296982406
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, mut k: usize, scanner: &mut Scanner) -> impl Printable {
    if k == 1 {
        return n * (n + 1) / 2;
    }
    let a: Vec<usize> = scanner.iter(n).collect();
    let mut factors = vec![];
    let mut x = 2;
    while x * x <= k {
        if k % x == 0 {
            let mut c = 1;
            k /= x;
            while k % x == 0 {
                c += 1;
                k /= x;
            }
            factors.push((x, c))
        }
        x += 1;
    }
    if k > 1 {
        factors.push((k, 1));
    }

    let mut l = 0;
    let m = factors.len();
    let mut count = vec![0; m];
    let mut cond = 0;
    let mask = (1 << m) - 1;
    let mut ans = 0;
    for (r, &x) in a.iter().enumerate() {
        let mut x = x;
        for (i, (&(p, c), cnt)) in factors.iter().zip(&mut count).enumerate() {
            while x % p == 0 {
                x /= p;
                *cnt += 1;
            }
            if *cnt >= c {
                cond |= 1 << i;
            }
        }
        while cond == mask {
            let mut x = a[l];
            for (i, (&(p, c), cnt)) in factors.iter().zip(&mut count).enumerate() {
                while x % p == 0 {
                    x /= p;
                    *cnt -= 1;
                }
                if *cnt < c {
                    cond &= mask ^ (1 << i);
                }
            }
            l += 1;
        }
        ans += l;
    }
    ans
}
