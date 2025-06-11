//! core logic only
//! submission: https://codeforces.com/problemset/submission/916/273727575
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize) -> impl Printable {
    use std::iter::repeat;

    for y in (1..20).rev() {
        let first = 1 << y;
        let cnt = n.saturating_mul(first);
        if cnt <= k {
            let mut ans = Vec::with_capacity(k);
            ans.extend(repeat(-y).take(cnt));
            while ans.len() < k {
                if let Some(x) = ans.pop() {
                    ans.push(x - 1);
                    ans.push(x - 1);
                }
            }
            return Ok("Yes".cr().then(Sep::<_, ' '>(ans)));
        }
    }
    for y in 0.. {
        let first = 1 << y;
        if first > n {
            break;
        }
        let cnt = n / first;
        let rest = n % first;
        if rest.count_ones() as usize + cnt <= k {
            let mut ans = Vec::with_capacity(k);
            ans.extend(repeat(y).take(cnt));
            for i in (0..64).rev() {
                if rest & (1 << i) != 0 {
                    ans.push(i);
                }
            }
            while ans.len() < k {
                if let Some(x) = ans.pop() {
                    ans.push(x - 1);
                    ans.push(x - 1);
                }
            }
            return Ok("Yes".cr().then(Sep::<_, ' '>(ans)));
        }
    }
    Err("No")
}
