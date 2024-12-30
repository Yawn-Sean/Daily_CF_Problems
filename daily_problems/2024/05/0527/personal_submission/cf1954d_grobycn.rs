// core logic only
// submission: https://codeforces.com/problemset/submission/1954/262880989
const MULTIPLE_TEST: bool = false;
const MOD: usize = 998244353;

fn solver(mut a: Vec<usize>) -> impl Printable {
    let n = a.len();
    let m = a.iter().sum::<usize>();
    a.sort_unstable();
    let mut count = vec![0; m + 1];
    count[0] = 1;
    let mut sum = 0;
    let mut ans = 0;
    for x in a {
        for s in (0..=sum).rev() {
            let d = if s >= x { (s + x + 1) / 2 } else { x };
            ans = (ans + (count[s] * d) % MOD) % MOD;
            count[s + x] = (count[s + x] + count[s]) % MOD;
        }
        sum += x;
    }
    ans
}
