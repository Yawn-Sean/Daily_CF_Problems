// core logic only
// submission: https://codeforces.com/problemset/submission/1129/259896592
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut min = vec![usize::MAX; n];
    let mut cnt = vec![0; n];
    for (mut a, mut b) in scanner.iter::<(usize, usize)>(m) {
        (a, b) = (a - 1, b - 1);
        if b < a {
            b += n;
        }
        cnt[a] += 1;
        min[a] = min[a].min(b);
    }
    let mut right = vec![0; n];
    let mut farthest = 0;
    for ((&dst, &c), r) in min.iter().zip(&cnt).zip(&mut right).rev() {
        if c != 0 {
            let dst = dst + (c - 1) * n;
            farthest = farthest.max(dst);
        }
        *r = farthest;
    }

    let mut ans = Vec::with_capacity(n);
    farthest = 0;
    for (i, ((&dst, &c), &r)) in min.iter().zip(&cnt).zip(&right).enumerate() {
        let dist = match (r == 0, farthest == 0) {
            (true, false) => farthest + n - i,
            (false, true) => r - i,
            _ => (farthest + n).max(r) - i,
        };
        ans.push(dist);
        if c != 0 {
            let dst = dst + (c - 1) * n;
            farthest = farthest.max(dst);
        }
    }
    Sep::<_, ' '>(ans)
}
