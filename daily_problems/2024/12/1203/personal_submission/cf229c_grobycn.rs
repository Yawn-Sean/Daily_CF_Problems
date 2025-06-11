//! core logic only
//! submission: https://codeforces.com/problemset/submission/229/294634531
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    if n < 3 {
        return 0;
    }
    let mut deg = vec![0; n];
    scanner.iter::<(usize, usize)>(m).for_each(|(u, v)| {
        deg[u - 1] += 1;
        deg[v - 1] += 1;
    });
    n * (n - 1) * (n - 2) / 6 - deg.iter().map(|&d| d * (n - 1 - d)).sum::<usize>() / 2
}
