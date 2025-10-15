//! core logic only
//! submission: https://codeforces.com/problemset/submission/222/322672781
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, x: usize, scanner: &mut Scanner) -> impl Printable {
    let mut a: Vec<usize> = scanner.iter(n).collect();
    let mut b: Vec<usize> = scanner.iter(n).collect();
    a.sort_unstable();
    b.sort_unstable();

    let mut b = b.into_iter().rev().peekable();
    let mut cnt = 0;
    for &ai in a.iter() {
        if b.next_if(|&bj| ai + bj >= x).is_some() {
            cnt += 1;
        }
    }
    (1, cnt)
}
