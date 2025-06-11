//! core logic only
//! submission: https://codeforces.com/problemset/submission/748/284313492
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    const MAXA: usize = 10_000_000;
    let mut count = vec![0; MAXA + 1];
    let mut sum = 0;
    for ai in scanner.iter::<usize>(n) {
        sum += ai;
        count[ai] += 1;
    }
    if sum < k {
        return Err(-1);
    }
    let mut acc = 0;
    let mut r = MAXA;
    for i in (2..=MAXA).rev() {
        acc += count[i];
        while (r + 1) / 2 >= i {
            acc -= count[r];
            r -= 1;
        }
        if acc >= k {
            return Ok(i);
        }
        let h1 = i / 2;
        let h2 = i - h1;
        count[h1] += count[i];
        count[h2] += count[i];
    }
    Ok(1)
}
