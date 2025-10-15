//! core logic only
//! submission: https://codeforces.com/problemset/submission/911/313727646
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let prefix: Vec<usize> = scanner.iter(k).collect();
    let mut suffix = Vec::with_capacity(n - k);
    let mut stk = vec![];
    let mut ord = 1;
    for &x in prefix.iter() {
        while let Some(&y) = stk.last() {
            if y == ord {
                ord += 1;
                stk.pop();
            } else {
                if y < x {
                    return Err(-1);
                }
                break;
            }
        }
        if x == ord {
            ord += 1;
        } else {
            stk.push(x);
        }
    }

    while ord <= n {
        let y = stk.pop().unwrap_or(n + 1);
        suffix.extend((ord..y).rev());
        ord = y + 1;
    }
    Ok(Sep::<_, ' '>(prefix.into_iter().chain(suffix)))
}
