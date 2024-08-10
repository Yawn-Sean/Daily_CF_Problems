//! core logic only
//! submission: https://codeforces.com/problemset/submission/622/271190745
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let mut count = vec![1; n];
    for (i, w) in a.windows(2).enumerate() {
        if w[0] == w[1] {
            count[i + 1] += count[i];
        }
    }
    let ans: Vec<_> = scanner.iter::<(usize, usize, usize)>(m)
        .map(|(l, r, x)| {
            if a[r - 1] != x {
                return Ok(r);
            }
            if count[r - 1] >= r + 1 - l {
                return Err(-1);
            }
            Ok(r - count[r - 1])
        }).collect();
    Sep::<_, '\n'>(ans)
}
