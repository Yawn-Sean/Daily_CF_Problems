//! core logic only
//! submission: https://codeforces.com/problemset/submission/2052/309351839
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, m: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let d: Vec<usize> = scanner.iter(n).collect();
    let mut l: Vec<usize> = scanner.iter(m).collect();
    for i in 1..m {
        l[i] += l[i - 1];
    }
    let t: Vec<usize> = scanner.iter(q).collect();

    let mut indice: Vec<_> = (0..n).collect();
    indice.sort_unstable_by_key(|&i| d[i]);
    let mut s = d.clone();
    let mut last = usize::MAX;
    for &i in indice.iter().rev() {
        s[i] = d[i].min(last) - a[i];
        last = s[i];
    }
    let mut psum = vec![0; n + 1];
    for (i, &idx) in indice.iter().enumerate() {
        psum[i + 1] = psum[i] + a[idx];
    }

    let ans: Vec<_> = t
        .iter()
        .map(|&tk| {
            let p = indice.partition_point(|&i| s[i] < tk);
            let sum = psum[p];
            let mx = if p == 0 {
                tk
            } else {
                let i = indice[p - 1];
                tk.max(s[i] + a[i])
            };
            let rest = mx - sum;
            l.partition_point(|&x| x <= rest)
        })
        .collect();
    Sep::<_, ' '>(ans)
}
