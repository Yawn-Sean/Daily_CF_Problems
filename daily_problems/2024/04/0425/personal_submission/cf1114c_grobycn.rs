// core logic only
// submission: https://codeforces.com/problemset/submission/1114/258120172
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, mut b: usize) -> impl Printable {
    let mut ans = usize::MAX;
    let mut p = 2;
    while p * p <= b {
        if b % p == 0 {
            let mut cnt = 1;
            b /= p;
            while b % p == 0 {
                cnt += 1;
                b /= p;
            }
            let mut cnt2 = 0;
            let mut mp = p;
            while mp <= n {
                cnt2 += n / mp;
                mp = mp.saturating_mul(p);
            }
            ans = ans.min(cnt2 / cnt);
        }
        p += 1;
    }
    if b > 1 {
        let mut cnt = 0;
        let mut mp = b;
        while mp <= n {
            cnt += n / mp;
            mp = mp.saturating_mul(b);
        }
        ans = ans.min(cnt);
    }
    ans
}
