//! core logic only
//! submission: https://codeforces.com/problemset/submission/1172/271940489
const MULTIPLE_TEST: bool = false;
const MOD: usize = 998_244_353;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut deg = vec![0; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(n - 1) {
        (u, v) = (u - 1, v - 1);
        deg[u] += 1;
        deg[v] += 1;
    }

    let mut factorials = vec![1; n];
    for i in 1..n {
        factorials[i] = (factorials[i - 1] * i) % MOD;
    }
    let mut ans = (n * factorials[deg[0]]) % MOD;
    for &d in deg[1..].iter() {
        ans = (ans * factorials[d]) % MOD;
    }
    ans
}
