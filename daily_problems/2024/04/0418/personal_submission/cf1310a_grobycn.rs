// core logic only
// submission: https://codeforces.com/contest/1310/submission/257184047
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let t: Vec<usize> = scanner.iter(n).collect();
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_unstable_by_key(|&i| a[i]);
    let mut i = 0;
    let mut hp = std::collections::BinaryHeap::new();
    let mut x = 0;
    let mut sum = 0;
    let mut ans = 0;
    while i < n {
        let y = a[indices[i]];
        while x < y {
            match hp.pop() {
                Some(t) => {
                    sum -= t;
                    ans += sum;
                    x += 1;
                }
                None => {
                    x = y;
                    break;
                }
            }
        }
        let mut e = i;
        while e < n && a[indices[e]] == a[indices[i]] {
            let ti = t[indices[e]];
            hp.push(ti);
            sum += ti;
            e += 1;
        }
        i = e;
    }
    while let Some(t) = hp.pop() {
        sum -= t;
        ans += sum;
    }
    ans
}
