//! core logic only
//! submission: https://codeforces.com/problemset/submission/1463/300857873
const MULTIPLE_TEST: bool = true;

fn solver(b: Vec<usize>) -> impl Printable {
    let n = b.len();
    let mut a = Vec::with_capacity(n);
    a.extend(1..b[0]);
    for w in b.windows(2) {
        a.extend(w[0] + 1..w[1]);
    }
    a.extend(b[n - 1] + 1..=2 * n);

    let mut iter = a.iter().peekable();
    let mut max_x = n;
    for (i, &bi) in b.iter().enumerate() {
        while iter.next_if(|&&ai| ai < bi).is_some() {}
        if iter.next().is_none() {
            max_x = i;
            break;
        }
    }
    let mut iter = a.iter().rev().peekable();
    let mut max_y = n;
    for (i, &bi) in b.iter().rev().enumerate() {
        while iter.next_if(|&&ai| ai > bi).is_some() {}
        if iter.next().is_none() {
            max_y = i;
            break;
        }
    }
    max_x + 1 - (n - max_y)
}
