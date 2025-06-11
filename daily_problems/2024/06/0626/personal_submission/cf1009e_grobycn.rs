// core logic only
// submission: https://codeforces.com/problemset/submission/1009/267526985
const MULTIPLE_TEST: bool = false;
const MOD: usize = 998244353;

fn solver(a: Vec<usize>) -> impl Printable {
    let n = a.len();
    let mut power2 = vec![1; n + 1];
    for i in 1..=n {
        power2[i] = (2 * power2[i - 1]) % MOD;
    }
    let mut ans = 0;
    for (&ai, i) in a.iter().zip(1..) {
        if i == n {
            ans = (ans + ai) % MOD;
        } else {
            ans = (ans + ((power2[n - i] + (power2[n - 1 - i] * (n - i)) % MOD) % MOD) * ai) % MOD;
        }
    }
    ans
}
