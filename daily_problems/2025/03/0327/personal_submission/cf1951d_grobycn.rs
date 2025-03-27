//! core logic only
//! submission: https://codeforces.com/problemset/submission/1951/312695091
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, k: usize) -> impl Printable {
    let ans = if n == k {
        vec![1]
    } else if 2 * (k - 1) < n {
        vec![n + 1 - k, 1]
    } else {
        return Err("NO");
    };
    Ok("YES".cr().then(ans.len()).cr().then(Sep::<_, ' '>(ans)))
}
