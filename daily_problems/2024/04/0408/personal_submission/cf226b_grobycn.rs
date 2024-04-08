// core logic only
// submission: https://codeforces.com/contest/226/submission/255625826
const MULTIPLE_TEST: bool = false;

fn solver(mut a: Vec<i64>, q: usize, scanner: &mut Scanner) -> impl Printable {
    a.sort_unstable_by_key(|&x| -x);
    let n = a.len();
    let mut presum = Vec::with_capacity(n + 1);
    presum.push(0);
    for (i, &x) in a.iter().enumerate() {
        presum.push(presum[i] + x);
    }
    let mut ans1 = -1;
    let ans: Vec<_> = scanner
        .iter(q)
        .map(|k: usize| {
            if k == 1 && ans1 != -1 {
                return ans1;
            }
            let mut i = 1;
            let mut len = k;
            let mut dep = 1;
            let mut ans = 0;
            while i < n {
                let cnt = (n - i).min(len);
                ans += dep * (presum[i + cnt] - presum[i]);
                len *= k;
                i += cnt;
                dep += 1;
            }
            if k == 1 {
                ans1 = ans;
            }
            ans
        })
        .collect();
    Sep::<_, ' '>(ans)
}
