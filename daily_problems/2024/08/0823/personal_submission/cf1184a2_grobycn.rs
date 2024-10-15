//! core logic only
//! submission: https://mirror.codeforces.com/problemset/submission/1184/277783822
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, s: String) -> impl Printable {
    let cnt1 = s.bytes().filter(|&b| b == b'1').count();
    if cnt1 == 0 {
        return n;
    }
    if cnt1 & 1 != 0 {
        return 0;
    }
    let mut ans = 1;
    let mut memo = vec![0; n];
    memo[1] = 1;
    let s = s.as_bytes();
    for k in 2..n {
        if n % k != 0 {
            ans += memo[gcd(n, k)];
            continue;
        }
        if (0..k).all(|start| (start..n).step_by(k).filter(|&i| s[i] == b'1').count() & 1 == 0) {
            memo[k] = 1;
            ans += 1;
        }
    }
    ans
}

fn gcd(mut a: usize, mut b: usize) -> usize {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}
