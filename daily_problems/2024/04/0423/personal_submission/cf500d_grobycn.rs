// core logic only
// submission: https://codeforces.com/problemset/submission/500/257867662
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let mut edges: Vec<(usize, usize, usize)> = scanner.iter(n - 1).collect();
    for (i, &(a, b, _)) in edges.iter().enumerate() {
        adj[a - 1].push((b - 1, i));
        adj[b - 1].push((a - 1, i));
    }

    fn dfs(adj: &[Vec<(usize, usize)>], cur: usize, fa: usize, count: &mut [usize]) -> usize {
        let n = adj.len();
        let mut ret = 1;
        for &(next, eidx) in &adj[cur] {
            if next == fa {
                continue;
            }
            let c1 = dfs(adj, next, cur, count);
            let c2 = n - c1;
            count[eidx] = c1 * (c1 - 1) / 2 * c2 + c1 * c2 * (c2 - 1) / 2;
            ret += c1;
        }
        ret
    }

    let mut count = vec![0; n - 1];
    dfs(&adj, 0, 0, &mut count);
    let tot = n * (n - 1) * (n - 2) / 6;
    let mut e = 0u128;
    for (&c, &(_, _, l)) in count.iter().zip(&edges) {
        e += (c * l) as u128;
    }

    let q = usize::from_scanner(scanner);
    let ans: Vec<_> = scanner
        .iter(q)
        .map(|(r, w): (usize, usize)| {
            let r = r - 1;
            let l = edges[r].2;
            e -= ((l - w) * count[r]) as u128;
            edges[r].2 = w;
            ((2 * e) as f64) / (tot as f64)
        })
        .collect();
    Sep::<_, '\n'>(ans)
}
