//! core logic only
//! submission: https://codeforces.com/problemset/submission/818/316813651
const MULTIPLE_TEST: bool = false;

fn solver(d: usize, n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut sofas: Vec<(usize, usize, usize, usize)> = scanner.iter(d).collect();
    let mut countl = vec![0; n + 2];
    let mut countr = vec![0; n + 2];
    let mut countt = vec![0; m + 2];
    let mut countb = vec![0; m + 2];
    for (x1, y1, x2, y2) in sofas.iter_mut() {
        if x1 > x2 {
            std::mem::swap(x1, x2);
        }
        if y1 > y2 {
            std::mem::swap(y1, y2);
        }
        countl[*x1] += 1;
        countr[*x2] += 1;
        countt[*y1] += 1;
        countb[*y2] += 1;
    }
    for i in 1..n + 2 {
        countl[i] += countl[i - 1];
    }
    for i in (1..n + 2).rev() {
        countr[i - 1] += countr[i];
    }
    for i in 1..m + 2 {
        countt[i] += countt[i - 1];
    }
    for i in (1..m + 2).rev() {
        countb[i - 1] += countb[i];
    }

    let (cntl, cntr, cntt, cntb) = <(usize, usize, usize, usize)>::from_scanner(scanner);
    for (i, &(x1, y1, x2, y2)) in sofas.iter().enumerate() {
        let cl = countl[x2 - 1] - usize::from(x1 < x2);
        let cr = countr[x1 + 1] - usize::from(x1 < x2);
        let ct = countt[y2 - 1] - usize::from(y1 < y2);
        let cb = countb[y1 + 1] - usize::from(y1 < y2);
        if cl == cntl && cr == cntr && ct == cntt && cb == cntb {
            return Ok(i + 1);
        }
    }
    Err(-1)
}
