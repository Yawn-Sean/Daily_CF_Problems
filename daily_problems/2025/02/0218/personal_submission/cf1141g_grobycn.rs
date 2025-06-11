//! core logic only
//! submission: https://codeforces.com/problemset/submission/1141/306668806
const MULTIPLE_TEST: bool = false;
fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (i, (mut x, mut y)) in scanner.iter::<(usize, usize)>(n - 1).enumerate() {
        (x, y) = (x - 1, y - 1);
        adj[x].push((y, i));
        adj[y].push((x, i));
    }
    let mut degs = adj.iter().map(|nb| nb.len()).collect::<Vec<_>>();
    degs.sort_unstable();
    let r = degs[n - 1 - k];
    let mut ans = vec![0; n - 1];

    let mut stk = vec![(0, 0)];
    while let Some((cur, forbid)) = stk.pop() {
        if adj[cur].len() > r {
            for &(next, eidx) in &adj[cur] {
                if ans[eidx] != 0 {
                    continue;
                }
                ans[eidx] = 1;
                stk.push((next, 1));
            }
        } else {
            let mut company = 1;
            for &(next, eidx) in &adj[cur] {
                if ans[eidx] != 0 {
                    continue;
                }
                if company == forbid {
                    company += 1;
                }
                ans[eidx] = company;
                stk.push((next, company));
                company += 1;
            }
        }
    }
    r.cr().then(Sep::<_, ' '>(ans))
}
