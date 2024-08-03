// core logic only
// submission: https://codeforces.com/contest/1175/submission/259435339
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    scanner
        .iter(n)
        .collect::<Vec<u32>>()
        .windows(k + 1)
        .map(|w| ((w[k] + 1 - w[0]) / 2, (w[k] + w[0]) / 2))
        .min_by_key(|&(fkx, _)| fkx)
        .map(|(_, x)| x)
        .unwrap()
}
