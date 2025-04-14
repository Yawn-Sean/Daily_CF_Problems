//! core logic only
//! submission: https://codeforces.com/problemset/submission/258/315581530
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(mut m: usize) -> impl Printable {
    fn dp(
        digits: &[usize],
        i: usize,
        c: usize,
        is_limit: bool,
        is_num: bool,
        memo: &mut [Vec<[usize; 10]>],
    ) -> [usize; 10] {
        if i == digits.len() {
            let mut ret = [0; 10];
            if is_num {
                ret[c] = 1;
            }
            return ret;
        }
        if !is_limit && is_num && memo[i][c][0] != usize::MAX {
            return memo[i][c];
        }
        let mut ret = [0; 10];
        let upper = if is_limit { digits[i] } else { 9 };
        for d in 0..=upper {
            let c = c + usize::from(d == 4 || d == 7);
            let is_limit = is_limit && d == upper;
            let is_num = is_num || d != 0;
            let cnt = dp(digits, i + 1, c, is_limit, is_num, memo);
            for (sum, c) in ret.iter_mut().zip(cnt) {
                *sum += c;
            }
        }
        if !is_limit && is_num {
            memo[i][c] = ret;
        }
        ret
    }

    let mut digits = vec![];
    while m > 0 {
        digits.push(m % 10);
        m /= 10;
    }
    digits.reverse();
    let mut memo = vec![vec![[usize::MAX; 10]; 10]; digits.len()];
    let mut count = dp(&digits, 0, 0, true, false, &mut memo);

    fn backtrack(
        count: &mut [usize; 10],
        parties: usize,
        cnt47: usize,
        ways: usize,
        ans: &mut usize,
    ) {
        if parties == 0 {
            *ans = (*ans + ways * count[cnt47 + 1..].iter().sum::<usize>()) % MOD;
            return;
        }
        for i in 0..10 - cnt47 {
            if count[i] > 0 {
                let ways = (ways * count[i]) % MOD;
                count[i] -= 1;
                backtrack(count, parties - 1, cnt47 + i, ways, ans);
                count[i] += 1;
            }
        }
    }

    let mut ans = 0;
    backtrack(&mut count, 6, 0, 1, &mut ans);
    ans
}
