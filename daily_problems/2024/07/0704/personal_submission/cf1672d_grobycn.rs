// core logic only
// https://codeforces.com/contest/1672/submission/268783697
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let mut it = a.into_iter();
    let mut count = vec![0; n + 1];
    let mut prev = usize::MAX;
    for x in scanner.iter::<usize>(n) {
        if prev == x && count[x] > 0 {
            count[x] -= 1;
            continue;
        }
        let mut matched = false;
        while let Some(y) = it.next() {
            if y != x {
                count[y] += 1;
            } else {
                matched = true;
                break;
            }
        }
        if !matched {
            return "NO";
        }
        prev = x;
    }
    "YES"
}
