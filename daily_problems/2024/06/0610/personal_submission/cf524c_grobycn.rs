// core logic only
// submission: https://codeforces.com/contest/524/submission/265001271
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut a: Vec<_> = scanner
        .iter(n)
        .map(|ai: usize| (1..=k).map(move |c| (c * ai, c)))
        .flatten()
        .collect();
    a.sort_unstable();
    a.dedup_by(|r, l| {
        if r.0 == l.0 {
            r.1 = r.1.min(l.1);
            true
        } else {
            false
        }
    });

    let q = usize::from_scanner(scanner);
    let ans: Vec<_> = scanner
        .iter(q)
        .map(|x: usize| {
            let mut ans = usize::MAX;
            if let Ok(i) = a.binary_search_by_key(&x, |&(y, _)| y) {
                ans = a[i].1;
            }
            let mut l = 0;
            for (r, &(y, c)) in a.iter().enumerate().rev() {
                while l < r && a[l].0 + y < x {
                    l += 1;
                }
                if l == r {
                    break;
                }
                if a[l].0 + y == x && c + a[l].1 <= k {
                    ans = ans.min(c + a[l].1);
                }
            }
            if ans == usize::MAX {
                Err(-1)
            } else {
                Ok(ans)
            }
        })
        .collect();
    Sep::<_, '\n'>(ans)
}
