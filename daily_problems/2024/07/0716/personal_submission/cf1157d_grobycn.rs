//! core logic only
//! submission: https://codeforces.com/problemset/submission/1157/270878991
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize) -> impl Printable {
    let mn = (1 + k) * k / 2;
    if n < mn {
        return Err("NO");
    }
    let mut ans: Vec<_> = (1..=k).collect();
    let mut rest = n - mn;
    let mut d = rest / k;
    ans[0] += d;
    rest %= k;
    for i in 1..k {
        let dmax = d + i - 1;
        let rem = (rest / (k - i)).min(dmax);
        rest -= rem * (k - i);
        d += rem;
        ans[i] += d;
    }
    if rest != 0 {
        return Err("NO");
    }
    Ok("YES".cr().then(Sep::<_, ' '>(ans)))
}
