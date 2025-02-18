//! core logic only
//! submission: https://codeforces.com/problemset/submission/769/279961300
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    const MAXA: usize = 10_000;
    let mut count = vec![0usize; MAXA + 1];
    for x in scanner.iter::<usize>(n) {
        count[x] += 1;
    }
    let mut ans = 0;
    if k == 0 {
        for &c in count.iter() {
            ans += c * (c - 1) / 2;
        }
        return ans;
    }
    let mut mask = (1 << k) - 1;
    while mask < (1 << 14) {
        for x in 0..=MAXA {
            let y = mask ^ x;
            if y < x {
                ans += count[x] * count[y];
            }
        }
        let lb = mask & !(mask - 1);
        let hi = mask + lb;
        let lo = ((hi ^ mask) / lb) >> 2;
        mask = hi | lo;
    }
    ans
}
