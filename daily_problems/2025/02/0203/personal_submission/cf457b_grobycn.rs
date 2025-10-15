//! core logic only
//! submission: https://codeforces.com/problemset/submission/457/304203045
const MULTIPLE_TEST: bool = false;

fn solver(m: usize, n: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(m).collect();
    let b: Vec<usize> = scanner.iter(n).collect();

    let suma: usize = a.iter().sum();
    let sumb: usize = b.iter().sum();

    fn join(to: &[usize], from_sum: usize) -> usize {
        let mut ans = from_sum;
        let mut mx = 0;
        for &x in to {
            ans += from_sum.min(x);
            mx = mx.max(x);
        }
        ans - from_sum.min(mx)
    }

    join(&a, sumb).min(join(&b, suma))
}
