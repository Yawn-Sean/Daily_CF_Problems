//! core logic only
//! submission: https://codeforces.com/problemset/submission/180/302237669
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut indices = vec![vec![]; m];
    for (i, x) in scanner.iter::<usize>(n).enumerate() {
        indices[x - 1].push(i);
    }

    let mut ans = 0;
    for indice in indices {
        let mut l = 0;
        for (i, &idx) in indice.iter().enumerate() {
            while idx - indice[l] > i + k - l {
                l += 1;
            }
            ans = ans.max(i + 1 - l);
        }
    }
    ans
}
