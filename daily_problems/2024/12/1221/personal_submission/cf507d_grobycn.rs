//! core logic only
//! submission: https://codeforces.com/problemset/submission/507/297790616
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, m: usize) -> impl Printable {
    let mut dp = vec![[0; 2]; k];
    let mut pow = 1;
    for i in 1..=n {
        let mut ndp = vec![[0; 2]; k];
        let lower = usize::from(i == n);
        for (r, count) in dp.iter().enumerate() {
            for (d, &cnt) in count.iter().enumerate() {
                for x in lower..10 {
                    let r = (r + x * pow) % k;
                    let d = d | usize::from(r == 0);
                    ndp[r][d] = (ndp[r][d] + cnt) % m;
                }
            }
        }
        for r in 1..10 {
            let r = (r * pow) % k;
            let cnt = &mut ndp[r][usize::from(r == 0)];
            *cnt = (*cnt + 1) % m;
        }
        pow = (pow * 10) % k;
        dp = ndp;
    }
    dp.iter().map(|r| r[1]).fold(0, |acc, x| (acc + x) % m)
}
