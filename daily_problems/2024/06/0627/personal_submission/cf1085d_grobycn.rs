// core logic only
// submission: https://codeforces.com/problemset/submission/1085/267660612
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, s: usize, scanner: &mut Scanner) -> impl Printable {
    let mut deg = vec![0; n];
    for (a, b) in scanner.iter::<(usize, usize)>(n - 1) {
        deg[a - 1] += 1;
        deg[b - 1] += 1;
    }
    let cnt = deg.into_iter().filter(|&x| x == 1).count();
    ((s * 2) as f64) / (cnt as f64)
}
