//! core logic only
//! submission: https://codeforces.com/problemset/submission/855/306884092
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(n - 1) {
        (u, v) = (u - 1, v - 1);
        adj[u].push(v);
        adj[v].push(u);
    }

    let (k, x) = <(usize, usize)>::from_scanner(scanner);

    fn dp(
        adj: &[Vec<usize>],
        cur: usize,
        fa: usize,
        m: usize,
        k: usize,
        x: usize,
    ) -> (Vec<usize>, Vec<usize>, Vec<usize>) {
        let (mut lt, mut eq, mut gt) = (vec![0; x + 1], vec![0; x + 1], vec![0; x + 1]);
        lt[0] = k - 1;
        eq[1] = 1;
        gt[0] = m - k;
        for &next in &adj[cur] {
            if next == fa {
                continue;
            }
            let (l, e, g) = dp(adj, next, cur, m, k, x);
            for tot in (0..=x).rev() {
                let (mut ltsum, mut eqsum, mut gtsum) = (0, 0, 0);
                for c in 0..=tot {
                    ltsum = (ltsum + lt[tot - c] * (l[c] + e[c] + g[c])) % MOD;
                    eqsum = (eqsum + eq[tot - c] * l[c]) % MOD;
                    gtsum = (gtsum + gt[tot - c] * (l[c] + g[c])) % MOD;
                }
                lt[tot] = ltsum;
                eq[tot] = eqsum;
                gt[tot] = gtsum;
            }
        }
        (lt, eq, gt)
    }

    let (lt, eq, gt) = dp(&adj, 0, 0, m, k, x);
    lt.iter()
        .chain(&eq)
        .chain(&gt)
        .fold(0, |acc, &x| (acc + x) % MOD)
}
