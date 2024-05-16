// core logic only
// submission: https://codeforces.com/problemset/submission/914/260943029
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: String, k: usize) -> impl Printable {
    if k == 0 {
        return 1;
    }
    if k == 1 {
        return n.len() - 1;
    }
    if k >= 10 {
        return 0;
    }
    let m = n.len();
    let mut op = vec![0; m + 1];
    for i in 2..=m {
        op[i] = op[i.count_ones() as usize] + 1;
    }

    fn dp(
        digits: &[u8],
        i: usize,
        is_limit: bool,
        cnt1: usize,
        memo: &mut [Vec<usize>],
        op: &[usize],
        k: usize,
    ) -> usize {
        if i == digits.len() {
            return usize::from(op[cnt1] + 1 == k);
        }
        if !is_limit && memo[i][cnt1] != usize::MAX {
            return memo[i][cnt1];
        }
        let upper = if is_limit { digits[i] } else { b'1' };
        let mut ret = 0;
        for d in b'0'..=upper {
            let is_limit = is_limit && d == upper;
            let cnt1 = cnt1 + usize::from(d == b'1');
            ret = (ret + dp(digits, i + 1, is_limit, cnt1, memo, op, k)) % MOD;
        }
        if !is_limit {
            memo[i][cnt1] = ret;
        }
        ret
    }

    let mut memo = vec![vec![usize::MAX; m + 1]; n.len()];
    dp(n.as_bytes(), 0, true, 0, &mut memo, &op, k)
}
