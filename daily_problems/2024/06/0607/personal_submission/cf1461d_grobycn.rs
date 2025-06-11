// core logic
// submission: https://codeforces.com/contest/1461/submission/264593969
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashSet;
    let mut a: Vec<usize> = scanner.iter(n).collect();
    a.sort_unstable();
    let mut presum = Vec::with_capacity(n + 1);
    presum.push(0);
    for (i, &x) in a.iter().enumerate() {
        presum.push(presum[i] + x)
    }

    fn divide_and_conquer(
        a: &[usize],
        psum: &[usize],
        l: usize,
        r: usize,
        sums: &mut HashSet<usize>,
    ) {
        let sum = psum[r] - psum[l];
        sums.insert(sum);
        let mid = (a[r - 1] + a[l]) / 2;
        let p = a.partition_point(|&x| x <= mid);
        if l == p || p == r {
            return;
        }
        divide_and_conquer(a, psum, l, p, sums);
        divide_and_conquer(a, psum, p, r, sums);
    }
    let mut sums = HashSet::new();
    divide_and_conquer(&a, &presum, 0, n, &mut sums);

    let ans: Vec<_> = scanner
        .iter(q)
        .map(|s: usize| if sums.contains(&s) { "YES" } else { "NO" })
        .collect();
    Sep::<_, '\n'>(ans)
}
