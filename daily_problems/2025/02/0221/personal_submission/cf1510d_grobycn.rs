//! core logic only
//! submission: https://codeforces.com/problemset/submission/1510/307279545
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, d: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<_> = scanner
        .iter::<usize>(n)
        .filter(|&x| ((d & 1 == 0) || (x & 1 != 0)) && ((d % 5 == 0) || (x % 5 != 0)))
        .collect();

    // dp[d]: minimum product of excluded nums while last digit of product of selected subset is d.
    let mut dp = [usize::MAX; 10];
    dp[1] = 1;
    let mut from = vec![[usize::MAX; 10]; n];

    for (i, &ai) in a.iter().enumerate() {
        let mut ndp = [usize::MAX; 10];
        for r in 0..10 {
            // discard ai
            let p = dp[r].saturating_mul(ai);
            if ndp[r] > p {
                ndp[r] = p;
                from[i][r] = r;
            }
            // choose ai
            let nr = (r * ai) % 10;
            if ndp[nr] > dp[r] {
                ndp[nr] = dp[r];
                from[i][nr] = r;
            }
        }
        dp = ndp;
    }
    if dp[d] == usize::MAX {
        return Err(-1);
    }

    let mut r = d;
    let mut ans = vec![];
    for (&ai, prev) in a.iter().zip(&from).rev() {
        let pr = prev[r];
        if (pr * ai) % 10 == r {
            ans.push(ai);
        }
        r = pr;
    }
    if ans.is_empty() {
        return Err(-1);
    }
    Ok(ans.len().cr().then(Sep::<_, ' '>(ans)))
}
