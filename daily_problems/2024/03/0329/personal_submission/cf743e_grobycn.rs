// core logic only
// submission: https://codeforces.com/contest/743/submission/253948432
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut presum = vec![vec![0; n + 1]; 8];
    for (i, x) in scanner.iter::<usize>(n).enumerate() {
        presum[x - 1][i + 1] = 1;
    }
    presum.iter_mut().for_each(|psum| {
        for i in 1..=n {
            psum[i] += psum[i - 1];
        }
    });

    let mut ans = 0;
    for x in 0..=n / 8 {
        let mut dp = vec![vec![usize::MAX; 1 << 8]; 8];
        dp[0][0] = 0;
        for extra in 0..8 {
            for mask in 0..1 << 8 {
                if dp[extra][mask] > n {
                    continue;
                }
                let cur = dp[extra][mask];
                for next in 0..8 {
                    if mask & (1 << next) != 0 {
                        continue;
                    }
                    let psum = &presum[next];
                    let mask1 = mask | (1 << next);
                    for (i, extra1) in (extra..=(extra + 1).min(7)).enumerate() {
                        let target = psum[cur] + x + i;
                        let idx = psum.partition_point(|&c| c < target);
                        dp[extra1][mask1] = dp[extra1][mask1].min(idx);
                    }
                }
            }
        }
        for extra in 0..8 {
            if dp[extra][(1 << 8) - 1] <= n {
                ans = ans.max(x * 8 + extra);
            }
        }
    }
    ans
}
