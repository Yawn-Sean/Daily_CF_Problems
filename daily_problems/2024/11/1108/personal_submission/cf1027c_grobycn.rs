//! core logic only
//! submission: https://codeforces.com/problemset/submission/1027/290542745
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashMap;
    let mut count = HashMap::new();
    for ai in scanner.iter::<usize>(n) {
        let e = count.entry(ai).or_insert(0);
        *e += 1;
        if *e == 4 {
            return (ai, ai, ai, ai);
        }
    }
    let mut candidates: Vec<_> = count
        .into_iter()
        .filter_map(|(x, c)| if c >= 2 { Some(x) } else { None })
        .collect();
    candidates.sort_unstable();

    let (mut a, mut b) = (1, 10_000);
    for w in candidates.windows(2) {
        let (c, d) = (w[0], w[1]);
        if d * a < b * c {
            (a, b) = (c, d);
        }
    }
    (a, b, a, b)
}
