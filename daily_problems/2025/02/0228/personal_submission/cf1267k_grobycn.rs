//! core logic only
//! submission: https://codeforces.com/problemset/submission/1267/308272484
const MULTIPLE_TEST: bool = true;

fn solver(mut k: usize) -> impl Printable {
    let mut count = [0; 20];
    let mut x = 2;
    while k > 0 {
        count[k % x] += 1;
        k /= x;
        x += 1;
    }

    let mut fac = [0; 20];
    fac[0] = 1;
    for i in 1..20 {
        fac[i] = fac[i - 1] * i;
    }
    let comb = |n: usize, m: usize| fac[n] / fac[m] / fac[n - m];
    let mut ans = 1;
    let mut excluded = 1;
    let mut slot = 0;
    x -= 1;
    while x > 1 {
        x -= 1;
        slot += 1;
        let c = count[x];
        if c > 0 {
            ans *= comb(slot, c);
            excluded *= if slot - 1 >= c { comb(slot - 1, c) } else { 0 };
            slot -= c;
        }
    }
    ans - excluded - 1
}
