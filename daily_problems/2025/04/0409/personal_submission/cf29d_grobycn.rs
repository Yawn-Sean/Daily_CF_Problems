//! core logic only
//! submission: https://codeforces.com/problemset/submission/29/314747350
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(n - 1) {
        (u, v) = (u - 1, v - 1);
        adj[u].push(v);
        adj[v].push(u);
    }

    fn dfs(adj: &[Vec<usize>], cur: usize, from: usize, repr: &mut [usize]) -> usize {
        repr[cur] = cur;
        let mut leaves = 0;
        for &next in &adj[cur] {
            if next == from {
                continue;
            }
            leaves += dfs(adj, next, cur, repr);
            repr[cur] = repr[next];
        }
        if repr[cur] == cur {
            leaves += 1;
        }
        leaves
    }

    fn dfs2(
        adj: &[Vec<usize>],
        cur: usize,
        from: usize,
        order: &mut impl Iterator<Item = usize>,
        ans: &mut Vec<usize>,
    ) -> bool {
        ans.push(cur);
        let mut isleaf = true;
        for &next in &adj[cur] {
            if next == from {
                continue;
            }
            if !dfs2(adj, next, cur, order, ans) {
                return false;
            }
            isleaf = false;
            ans.push(cur);
        }
        if isleaf {
            return match order.next() {
                Some(u) if u == cur => true,
                _ => false,
            };
        }
        true
    }

    let mut repr = vec![0; n];
    let k = dfs(&adj, 0, 0, &mut repr);
    let order: Vec<_> = scanner.iter(k).map(|x: usize| x - 1).collect();
    let mut rank = vec![0; n];
    for (i, &u) in order.iter().enumerate() {
        rank[u] = i;
    }
    let mut order = order.into_iter();

    let mut ans = Vec::with_capacity(2 * n - 1);
    adj.iter_mut()
        .for_each(|xs| xs.sort_unstable_by_key(|&i| rank[repr[i]]));
    if dfs2(&mut adj, 0, 0, &mut order, &mut ans) {
        Ok(Sep::<_, ' '>(ans.into_iter().map(|x| x + 1)))
    } else {
        Err(-1)
    }
}
