// core logic only
// submission: https://codeforces.com/problemset/submission/802/263882513
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::{BTreeSet, VecDeque};
    let mut a: Vec<usize> = scanner.iter(n).collect();
    let mut indices = vec![VecDeque::new(); n];
    for (i, x) in a.iter_mut().enumerate() {
        *x -= 1;
        indices[*x].push_back(i);
    }

    let mut set = BTreeSet::new();
    let mut ans = 0;
    let mut unused = n;
    for (i, &x) in a.iter().enumerate() {
        indices[x].pop_front();
        let next = *indices[x].front().unwrap_or(&unused);
        unused += 1;
        if !set.remove(&i) {
            if set.len() == k {
                let mx = *set.iter().next_back().unwrap();
                set.remove(&mx);
            }
            ans += 1;
        }
        set.insert(next);
    }
    ans
}
