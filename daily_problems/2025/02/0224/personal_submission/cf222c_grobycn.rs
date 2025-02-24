//! core logic only
//! submission: https://codeforces.com/problemset/submission/222/307543112
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    const MAXU: usize = 10_000_000;
    let mut lpf = vec![usize::MAX; MAXU + 1];
    let mut primes = vec![];
    for x in 2..=MAXU {
        if lpf[x] == usize::MAX {
            lpf[x] = primes.len();
            primes.push(x);
        }
        for (i, &p) in primes.iter().enumerate() {
            if p * x > MAXU {
                break;
            }
            lpf[p * x] = i;
            if x % p == 0 {
                break;
            }
        }
    }
    let k = primes.len();
    let prime_factor_count = |xs: &[usize]| {
        let mut cnt = vec![0; k];
        xs.iter().for_each(|&x| {
            let mut x = x;
            while x > 1 {
                let i = lpf[x];
                cnt[i] += 1;
                x /= primes[i];
            }
        });
        cnt
    };
    let mut a: Vec<usize> = scanner.iter(n).collect();
    let mut b: Vec<usize> = scanner.iter(m).collect();
    let mut cnta = prime_factor_count(&a);
    let mut cntb = prime_factor_count(&b);
    cnta.iter_mut().zip(&mut cntb).for_each(|(ca, cb)| {
        let common = std::cmp::min(*ca, *cb);
        *ca = common;
        *cb = common;
    });
    let mut simplify = |x: &mut usize, pcnt: &mut [usize]| {
        let mut y = *x;
        while y > 1 {
            let i = lpf[y];
            if pcnt[i] > 0 {
                pcnt[i] -= 1;
                *x /= primes[i];
            }
            y /= primes[i];
        }
    };
    a.iter_mut().for_each(|ai| simplify(ai, &mut cnta));
    b.iter_mut().for_each(|bi| simplify(bi, &mut cntb));
    (n, m)
        .cr()
        .then(Sep::<_, ' '>(a))
        .cr()
        .then(Sep::<_, ' '>(b))
}
