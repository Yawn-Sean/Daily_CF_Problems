//! core logic only
//! submission: https://codeforces.com/problemset/submission/538/274202122
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<i32>) -> impl Printable {
    let n = a.len();
    let nsqrt = 450;
    let mut ans = vec![0; n - 1];
    let mut diff = vec![0; n];
    for (i, &x) in a.iter().enumerate().skip(1) {
        for k in 1..n.min(nsqrt) {
            let p = (i - 1) / k;
            if a[p] > x {
                ans[k - 1] += 1;
            }
        }
        for p in 0..i.min(nsqrt + 2) {
            if a[p] <= x {
                continue;
            }
            // i / (p + 1) <= k
            // k <= (i - 1) / p
            let mink = ((i + p) / (p + 1)).max(nsqrt);
            let maxk = if p == 0 { n - 1 } else { (i - 1) / p };
            if maxk < mink {
                continue;
            }
            
            diff[mink - 1] += 1;
            diff[maxk] -= 1;
        }
    }

    let mut acc = 0;
    for (x, d) in ans.iter_mut().zip(diff) {
        acc += d;
        *x += acc;
    }
    Sep::<_, ' '>(ans)
}
