//! core logic only
//! submission: https://codeforces.com/problemset/submission/959/300045345
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<usize>) -> impl Printable {
    const M: usize = 2_000_000;
    let n = a.len();
    let mut primes = vec![];
    let mut lpf = vec![0; M + 1];
    for x in 2..=M {
        if lpf[x] == 0 {
            lpf[x] = x;
            primes.push(x);
        }
        for &p in &primes {
            if p * x > M {
                break;
            }
            lpf[x * p] = p;
            if x % p == 0 {
                break;
            }
        }
    }
    let mut used = vec![false; M + 1];
    let mut b = Vec::with_capacity(n);
    for &x in &a {
        let mut z = x;
        'outer: for mut y in x.. {
            z = y;
            while y != 1 {
                let p = lpf[y];
                if used[p] {
                    continue 'outer;
                }
                while lpf[y] == p {
                    y /= p;
                }
            }
            break;
        }
        let eq = z == x;
        b.push(z);
        while z != 1 {
            let p = lpf[z];
            used[p] = true;
            while lpf[z] == p {
                z /= p;
            }
        }
        if !eq {
            break;
        }
    }
    let rest = primes.into_iter().filter(|&p| !used[p]).take(n - b.len());
    b.extend(rest);
    Sep::<_, ' '>(b)
}
