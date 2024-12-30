// core logic only
// submission: https://codeforces.com/contest/1102/submission/260001681
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<u32>) -> impl Printable {
    const MOD: usize = 998244353;

    let mut last = std::collections::HashMap::new();
    for (i, &x) in a.iter().enumerate() {
        last.insert(x, i);
    }
    let mut ans = 1;
    let mut right = 0;
    for (i, &x) in a.iter().enumerate() {
        if i > right {
            ans = (ans * 2) % MOD;
            right = last[&x];
        } else {
            right = right.max(last[&x]);
        }
    }
    ans
}
