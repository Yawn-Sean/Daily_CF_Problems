//! core logic only
//! submission: https://codeforces.com/contest/425/submission/271551948
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let table: Vec<_> = (0..n)
        .map(|_| scanner.iter::<u128>(m).fold(0u128, |acc, x| (acc << 1) | x))
        .collect();
    let mut ans = u32::MAX;
    if n > k {
        let mask = (1u128 << m) - 1;
        for &fixed in table.iter() {
            let mut change = 0;
            for &row in table.iter() {
                change += (fixed ^ row)
                    .count_ones()
                    .min((fixed ^ row ^ mask).count_ones());
            }
            ans = ans.min(change);
        }
    } else {
        let mask = (1u32 << n) - 1;
        for fixed in 0..=mask {
            let mut change = 0;
            for c in 0..m {
                let col = table
                    .iter()
                    .map(|row| ((row >> c) & 1) as u32)
                    .fold(0u32, |acc, x| (acc << 1) | x);
                change += (fixed ^ col)
                    .count_ones()
                    .min((fixed ^ col ^ mask).count_ones());
            }
            ans = ans.min(change);
        }
    }
    if ans <= (k as u32) {
        Ok(ans)
    } else {
        Err(-1)
    }
}
