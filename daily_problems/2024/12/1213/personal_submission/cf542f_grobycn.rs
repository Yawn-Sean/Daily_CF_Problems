//! core logic only
//! submission: https://codeforces.com/problemset/submission/542/296307042
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, t: usize, scanner: &mut Scanner) -> impl Printable {
    use std::cmp::Reverse;
    use std::collections::BinaryHeap;

    let mut hp = BinaryHeap::new();
    for (ti, qi) in scanner.iter::<(usize, usize)>(n) {
        hp.push((Reverse(ti), qi));
    }
    while let Some(&(Reverse(ti), mut qi)) = hp.peek() {
        if ti >= t {
            break;
        }
        hp.pop();
        if let Some(&(Reverse(tj), qj)) = hp.peek() {
            if ti == tj {
                qi += qj;
                hp.pop();
            }
        }
        hp.push((Reverse(ti + 1), qi));
    }
    hp.pop().unwrap().1
}
