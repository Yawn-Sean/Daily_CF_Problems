// core logic only
// submission: https://codeforces.com/contest/744/submission/254101998
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut rcount = vec![0usize; 1 << n];
    let mut bcount = vec![0usize; 1 << n];
    let mut rcost = Vec::with_capacity(n);
    let mut bcost = Vec::with_capacity(n);

    for (i, (c, r, b)) in scanner.iter::<(String, usize, usize)>(n).enumerate() {
        if c == "R" {
            rcount[1 << i] += 1;
        } else {
            bcount[1 << i] += 1;
        }
        rcost.push(r);
        bcost.push(b);
    }

    let m = 1 << n;
    for mask in 0..m {
        let lb = mask & !(mask - 1);
        rcount[mask] = rcount[mask ^ lb] + rcount[lb];
        bcount[mask] = bcount[mask ^ lb] + bcount[lb];
    }

    let max_saved = n * (n - 1) / 2;
    let mut dp = vec![vec![usize::MAX / 2; max_saved + 1]; m];
    dp[0][0] = 0;

    for (mask, (&rcnt, &bcnt)) in rcount.iter().zip(&bcount).enumerate() {
        let max_saved = (rcnt + bcnt) * (rcnt + bcnt).saturating_sub(1) / 2;
        for (i, (&rc, &bc)) in rcost.iter().zip(&bcost).enumerate() {
            if mask & (1 << i) != 0 {
                continue;
            }
            let mask1 = mask | (1 << i);
            let rsav = rcnt.min(rc);
            let bsav = bcnt.min(bc);
            for j in 0..=max_saved {
                dp[mask1][j + rsav] = dp[mask1][j + rsav].min(dp[mask][j] + bc - bsav);
            }
        }
    }

    let total_red = rcost.iter().sum::<usize>();
    let mut mn = usize::MAX;
    for k in 0..=max_saved {
        mn = mn.min(dp[m - 1][k].max(total_red.saturating_sub(k)));
    }

    mn + n
}
