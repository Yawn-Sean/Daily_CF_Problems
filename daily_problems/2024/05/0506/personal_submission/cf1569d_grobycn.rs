// core logic only
// submission: https://codeforces.com/problemset/submission/1569/259772376
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashMap;
    let xs: Vec<usize> = scanner.iter(n).collect();
    let ys: Vec<usize> = scanner.iter(m).collect();
    let mut ps: Vec<(usize, usize)> = scanner.iter(k).collect();
    let mut ans = 0;
    ps.sort_unstable_by_key(|p| p.0);
    for w in xs.windows(2) {
        let l = ps.partition_point(|p| p.0 <= w[0]);
        let r = ps.partition_point(|p| p.0 < w[1]);
        let mut cnt = HashMap::new();
        let mut tot = 0;
        for &(_, y) in ps[l..r].iter() {
            tot += 1;
            *cnt.entry(y).or_insert(0) += 1;
        }
        ans += cnt.values().map(|&c| c * (tot - c)).sum::<usize>();
    }
    ps.sort_unstable_by_key(|p| p.1);
    for w in ys.windows(2) {
        let l = ps.partition_point(|p| p.1 <= w[0]);
        let r = ps.partition_point(|p| p.1 < w[1]);
        let mut cnt = HashMap::new();
        let mut tot = 0;
        for &(x, _) in ps[l..r].iter() {
            tot += 1;
            *cnt.entry(x).or_insert(0) += 1;
        }
        ans += cnt.values().map(|&c| c * (tot - c)).sum::<usize>();
    }
    ans / 2
}
