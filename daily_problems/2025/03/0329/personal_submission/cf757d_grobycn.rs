//! core logic only
//! submission: https://codeforces.com/problemset/submission/757/312931927
const MULTIPLE_TEST: bool = false;
const MOD: u32 = 1_000_000_007;

fn solver(n: usize, block: String) -> impl Printable {
    fn dp(xs: &[u8], i: usize, mask: usize, memo: &mut [Vec<u32>]) -> u32 {
        if i == xs.len() {
            return 0;
        }
        if memo[i][mask] != u32::MAX {
            return memo[i][mask];
        }
        let mut ret = 0;
        let mut x = 0;
        for j in i..xs.len() {
            x = 2 * x + (xs[j] - b'0');
            if x > 20 {
                break;
            }
            if x > 0 {
                let mask = mask | (1 << (x - 1));
                ret += u32::from((mask + 1).count_ones() == 1);
                ret += dp(xs, j + 1, mask, memo);
                ret %= MOD;
            }
        }
        memo[i][mask] = ret;
        ret
    }

    // MLE with usize
    let mut memo = vec![vec![u32::MAX; 1 << 20]; n];
    let mut ret = 0;
    for i in 0..n {
        ret += dp(block.as_bytes(), i, 0, &mut memo);
        ret %= MOD;
    }
    ret
}
