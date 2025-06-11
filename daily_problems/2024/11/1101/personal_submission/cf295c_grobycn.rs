//! core logic only
//! submission: https://codeforces.com/problemset/submission/295/289227595
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn powermod(mut e: usize, mut x: usize, m: usize) -> usize {
    let mut ret = 1;
    while x > 0 {
        if x & 1 != 0 {
            ret = (ret * e) % m;
        }
        e = (e * e) % m;
        x >>= 1;
    }
    ret
}

fn solver(n: usize, mut k: usize, scanner: &mut Scanner) -> impl Printable {
    k /= 50;
    let (mut cnt1, mut cnt2) = (0, 0);
    for x in scanner.iter::<usize>(n) {
        if x == 50 {
            cnt1 += 1;
        } else {
            cnt2 += 1;
        }
    }

    let mut fac = vec![1; n + 1];
    for i in 1..=n {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    let mut ifac = vec![0; n + 1];
    ifac[n] = powermod(fac[n], MOD - 2, MOD);
    for i in (1..=n).rev() {
        ifac[i - 1] = (ifac[i] * i) % MOD;
    }
    let comb = |n: usize, k: usize| (((fac[n] * ifac[k]) % MOD) * ifac[n - k]) % MOD;
    let mut dp = vec![vec![None; cnt2 + 1]; cnt1 + 1];
    dp[cnt1][cnt2] = Some(1);

    for ride in 1..4 * n {
        let mut ndp = vec![vec![None; cnt2 + 1]; cnt1 + 1];
        for (c1, row) in dp.iter().enumerate() {
            for (c2, some_way) in row.iter().enumerate() {
                if let Some(way) = some_way {
                    for x1 in 0..=c1.min(k) {
                        let m1 = comb(c1, x1);
                        for x2 in 0..=c2.min((k - x1) / 2) {
                            if x1 + x2 == 0 {
                                continue;
                            }
                            let m2 = comb(c2, x2);
                            let way = (((m1 * m2) % MOD) * way) % MOD;
                            let (c1, c2) = (cnt1 - c1 + x1, cnt2 - c2 + x2);
                            let way = (way + ndp[c1][c2].unwrap_or(0)) % MOD;
                            ndp[c1][c2] = Some(way);
                        }
                    }
                }
            }
        }
        if ride & 1 != 0 {
            if let Some(way) = ndp[cnt1][cnt2] {
                return Ok(ride.cr().then(way));
            }
        }
        dp = ndp;
    }
    Err((-1).cr().then(0))
}
