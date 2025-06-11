// core logic only
// submission: https://codeforces.com/problemset/submission/992/265775897
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<_> = scanner.iter::<usize>(n).collect();
    let mut cnt = vec![1; n];
    for i in 1..n {
        if a[i] == 1 && a[i - 1] == 1 {
            cnt[i] += cnt[i - 1];
        }
    }

    let mut ans = 0;
    for i in 0..n {
        let (mut prod, mut sum) = (1, 0);
        let mut idx = i;
        while idx <= i {
            let x = a[idx];
            let c = cnt[idx];
            if x == 1 {
                let c = cnt[idx];
                if prod % k == 0 {
                    if sum < prod / k && prod / k <= sum + c {
                        ans += 1;
                    }
                }
                sum += c;
                idx = idx.wrapping_sub(c);
            } else {
                prod = match prod.checked_mul(x) {
                    Some(p) => p,
                    _ => break,
                };
                sum += x;
                if prod == sum * k {
                    ans += 1;
                }
                idx = idx.wrapping_sub(1);
            }
        }
    }
    ans
}
