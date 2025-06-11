//! core logic only
//! submission: https://codeforces.com/problemset/submission/553/302236497
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, mut k: usize) -> impl Printable {
    let mut fib = vec![1; n];
    for i in 2..n {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    let mut ans = Vec::with_capacity(n);
    let mut i = 1;
    while i <= n {
        let r = n - i;
        if fib[r] >= k {
            ans.push(i);
            i += 1;
        } else {
            k -= fib[r];
            ans.push(i + 1);
            ans.push(i);
            i += 2;
        }
    }
    Sep::<_, ' '>(ans)
}
