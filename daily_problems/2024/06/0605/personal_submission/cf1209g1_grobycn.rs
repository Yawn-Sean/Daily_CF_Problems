// core logic only
// submission: https://codeforces.com/contest/1209/submission/264265726
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashMap;
    let mut indices = HashMap::new();
    let a: Vec<u32> = scanner.iter(n).collect();
    for (i, &x) in a.iter().enumerate() {
        indices.entry(x).or_insert(vec![]).push(i);
    }
    let (mut l, mut r) = (0, 0);
    let mut ans = 0;
    let mut mxcnt = 0;
    for (i, &x) in a.iter().enumerate() {
        let idxs = indices.get(&x).unwrap();
        if i <= r {
            mxcnt = mxcnt.max(idxs.len());
            r = r.max(*idxs.last().unwrap());
        } else {
            ans += r + 1 - l - mxcnt;
            l = i;
            r = *idxs.last().unwrap();
            mxcnt = idxs.len();
        }
    }
    ans + r + 1 - l - mxcnt
}
