//! core logic only
//! submission: https://codeforces.com/problemset/submission/332/311754215
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, p: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let orders: Vec<(i32, i32)> = scanner.iter(n).collect();
    let ord_inc1_dec0 = |&i: &usize| (orders[i].1, -orders[i].0);
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_unstable_by_key(ord_inc1_dec0);
    let mut ans = {
        let mut obey_candidates = Vec::with_capacity(p);
        obey_candidates.extend(indices[p - k..].iter().copied());
        obey_candidates.sort_unstable_by_key(|&i| (-orders[i].0, -orders[i].1));
        obey_candidates.truncate(k);
        obey_candidates
    };
    let mut used = vec![false; n];
    let mn = ans
        .iter()
        .inspect(|&i| used[*i] = true)
        .map(ord_inc1_dec0)
        .min()
        .unwrap();
    let m = indices.partition_point(|i| ord_inc1_dec0(i) <= mn);
    ans.extend(
        indices[..m]
            .iter()
            .rev()
            .copied()
            .filter(|&i| !used[i])
            .take(p - k),
    );
    Sep::<_, ' '>(ans.into_iter().map(|x| x + 1))
}
