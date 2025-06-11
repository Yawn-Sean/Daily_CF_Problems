//! core logic only
//! submission: https://codeforces.com/problemset/submission/1119/271938745
const MULTIPLE_TEST: bool = false;

fn solver(mut s: Vec<usize>, q: usize, scanner: &mut Scanner) -> impl Printable {
    let n = s.len();
    s.sort_unstable();
    let mut d: Vec<_> = s.windows(2).map(|w| w[1] - w[0]).collect();
    d.sort_unstable();
    let mut presum = vec![0; n];
    for (i, &x) in d.iter().enumerate() {
        presum[i + 1] = presum[i] + x;
    }

    let ans: Vec<_> = scanner.iter::<(usize, usize)>(q)
        .map(|(l, r)| {
            let len = r + 1 - l;
            let p = d.partition_point(|&x| x < len);
            len * (n - p) + presum[p]
        }).collect();

    Sep::<_, ' '>(ans)
}
