// core logic only
// submission: https://codeforces.com/problemset/submission/439/255982602
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut a: Vec<usize> = scanner.iter(n).collect();
    let mut b: Vec<usize> = scanner.iter(m).collect();
    a.sort_unstable();
    b.sort_unstable();
    a.iter()
        .zip(b.iter().rev())
        .take_while(|(a, b)| a < b)
        .map(|(a, b)| b - a)
        .sum::<usize>()
}
