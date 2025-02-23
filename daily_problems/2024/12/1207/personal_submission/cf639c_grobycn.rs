//! core logic only
//! submission: https://codeforces.com/problemset/submission/639/295337488
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: i64, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<i64> = scanner.iter(n + 1).collect();
    let mut normalized = a.clone();
    for i in 0..n {
        let x = normalized[i];
        let q = x.div_euclid(2);
        let r = x.rem_euclid(2);
        normalized[i] = r;
        normalized[i + 1] += q;
    }

    let first_non_zero = normalized.iter().position(|&x| x != 0).unwrap();
    let mut ans = 0;
    let mut sum = 0;
    for (i, (&ai, &normi)) in a.iter().zip(&normalized).enumerate().rev() {
        sum = 2 * sum + normi;
        if sum.abs() > 2 * k {
            break;
        }
        if i <= first_non_zero {
            let ai = (ai - sum).abs();
            if ai <= k {
                if i != n || ai != 0 {
                    ans += 1;
                }
            }
        }
    }
    ans
}
