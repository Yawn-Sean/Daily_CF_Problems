// core logic only
// submission: https://codeforces.com/contest/894/submission/262900605
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (x, y, w) in scanner.iter::<(usize, usize, usize)>(m) {
        adj[x - 1].push((y - 1, w));
    }
    let s = usize::from_scanner(scanner) - 1;

    fn dfs(
        adj: &[Vec<(usize, usize)>],
        cur: usize,
        dfn: &mut [usize],
        low: &mut [usize],
        clock: &mut usize,
        stack: &mut Vec<usize>,
        instk: &mut [bool],
        scc: &mut [usize],
        scc_cnt: &mut usize,
    ) {
        dfn[cur] = *clock;
        low[cur] = *clock;
        *clock += 1;
        stack.push(cur);
        instk[cur] = true;
        for &(next, _) in &adj[cur] {
            if dfn[next] == usize::MAX {
                dfs(adj, next, dfn, low, clock, stack, instk, scc, scc_cnt);
                low[cur] = low[cur].min(low[next]);
            } else if instk[next] {
                low[cur] = low[cur].min(dfn[next]);
            }
        }
        if low[cur] == dfn[cur] {
            while let Some(i) = stack.pop() {
                instk[i] = false;
                scc[i] = *scc_cnt;
                if i == cur {
                    break;
                }
            }
            *scc_cnt += 1;
        }
    }

    let mut dfn = vec![usize::MAX; n];
    let mut low = vec![usize::MAX; n];
    let mut scc = vec![usize::MAX; n];
    let mut scc_cnt = 0;
    let mut clock = 0;
    let mut stack = vec![];
    let mut instk = vec![false; n];
    dfs(
        &adj,
        s,
        &mut dfn,
        &mut low,
        &mut clock,
        &mut stack,
        &mut instk,
        &mut scc,
        &mut scc_cnt,
    );

    let sum = |w: usize| {
        let x = ((((8 * w + 1) as f64).sqrt() - 1.0) / 2.0).floor() as usize;
        w * (x + 1) - x * (x + 1) * (x + 2) / 6
    };

    let mut mashrooms = vec![0; scc_cnt];
    let mut new_adj = vec![vec![]; scc_cnt];
    for (from, edges) in adj.iter().enumerate() {
        let scc_no = scc[from];
        if scc_no == usize::MAX {
            continue;
        }
        for &(to, w) in edges {
            if scc[to] == scc_no {
                mashrooms[scc_no] += sum(w);
            } else {
                new_adj[scc_no].push((scc[to], w));
            }
        }
    }

    fn dfs2(
        adj: &[Vec<(usize, usize)>],
        cur: usize,
        values: &[usize],
        memo: &mut [usize],
    ) -> usize {
        if memo[cur] != usize::MAX {
            return memo[cur];
        }
        let mut mx = 0;
        for &(next, w) in &adj[cur] {
            mx = mx.max(dfs2(adj, next, values, memo) + w);
        }
        memo[cur] = mx + values[cur];
        memo[cur]
    }
    let mut memo = vec![usize::MAX; n];
    dfs2(&new_adj, scc_cnt - 1, &mashrooms, &mut memo)
}
