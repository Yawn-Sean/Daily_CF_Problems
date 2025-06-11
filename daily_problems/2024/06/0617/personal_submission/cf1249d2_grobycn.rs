// core logic only
// submission: https://codeforces.com/contest/1249/submission/266195908
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: i32, scanner: &mut Scanner) -> impl Printable {
    use std::collections::BinaryHeap;

    let segs: Vec<(usize, usize)> = scanner.iter(n).collect();
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_unstable_by_key(|&i| segs[i]);
    let mx = segs[indices[n - 1]].1;
    let mut diff = vec![0; 200_002];
    for &(l, r) in &segs {
        diff[l] += 1;
        diff[r + 1] -= 1;
    }

    let mut hp = BinaryHeap::new();
    let mut it = indices.iter().peekable();
    let mut sum = 0;
    let mut ans = vec![];
    for x in 1..200_002 {
        while let Some(&i) = it.next_if(|&&i| segs[i].0 <= x) {
            hp.push((segs[i].1, i));
        }
        sum += diff[x];
        while sum > k {
            if let Some((r, i)) = hp.pop() {
                diff[r + 1] += 1;
                sum -= 1;
                ans.push(i + 1);
            }
        }
    }
    ans.len().cr().then(Sep::<_, ' '>(ans))
}
