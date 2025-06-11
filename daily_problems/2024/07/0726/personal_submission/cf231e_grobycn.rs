//! core logic only
//! submission: https://codeforces.com/problemset/submission/231/272990119
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut a, mut b) in scanner.iter::<(usize, usize)>(m) {
        (a, b) = (a - 1, b - 1);
        adj[a].push(b);
        adj[b].push(a);
    }

    let mut scc = vec![usize::MAX; n];
    let mut scc_size = vec![];
    tarjan(
        &adj,
        0,
        0,
        &mut 0,
        &mut vec![usize::MAX; n],
        &mut vec![usize::MAX; n],
        &mut vec![],
        &mut vec![false; n],
        &mut scc,
        &mut scc_size,
    );

    let m = scc_size.len();
    let mut new_adj = vec![vec![]; m];
    for (cur, adj) in adj.iter().enumerate() {
        for &next in adj {
            let (cur, next) = (scc[cur], scc[next]);
            if cur != next {
                new_adj[cur].push(next);
            }
        }
    }

    let mut ancient = vec![[usize::MAX; 18]; m];
    let mut presum = vec![0; m];
    let mut depth = vec![0; m];
    lca(
        &new_adj,
        0,
        0,
        &scc_size,
        &mut depth,
        &mut presum,
        &mut ancient,
    );
    let q = usize::from_scanner(scanner);
    let ans: Vec<_> = scanner
        .iter::<(usize, usize)>(q)
        .map(|(mut x, mut y)| {
            (x, y) = (scc[x - 1], scc[y - 1]);
            if x == y {
                return 2;
            }
            let mut cnt = presum[x] + presum[y];
            if depth[x] > depth[y] {
                std::mem::swap(&mut x, &mut y);
            }
            let delta = depth[y] - depth[x];
            for i in 0..18 {
                if delta & (1 << i) != 0 {
                    y = ancient[y][i];
                }
            }
            if x != y {
                for i in (0..18).rev() {
                    if ancient[x][i] != ancient[y][i] {
                        x = ancient[x][i];
                        y = ancient[y][i];
                    }
                }
                y = ancient[y][0];
            }
            cnt -= presum[y];
            if y != 0 {
                cnt -= presum[ancient[y][0]];
            }
            powermod(2, cnt, MOD)
        })
        .collect();

    Sep::<_, '\n'>(ans)
}

fn powermod(mut e: usize, mut x: usize, m: usize) -> usize {
    let mut ret = 1;
    while x > 0 {
        if x & 1 != 0 {
            ret = (ret * e) % m;
        }
        e = (e * e) % m;
        x >>= 1;
    }
    ret
}

fn lca(
    adj: &[Vec<usize>],
    cur: usize,
    from: usize,
    scc_size: &[usize],
    depth: &mut [usize],
    presum: &mut [usize],
    ancient: &mut [[usize; 18]],
) {
    presum[cur] = presum[from] + usize::from(scc_size[cur] > 1);
    depth[cur] = depth[from] + 1;
    ancient[cur][0] = from;
    for i in 1..18 {
        ancient[cur][i] = ancient[ancient[cur][i - 1]][i - 1];
    }
    for &next in &adj[cur] {
        if next == from {
            continue;
        }
        lca(adj, next, cur, scc_size, depth, presum, ancient);
    }
}

fn tarjan(
    adj: &[Vec<usize>],
    cur: usize,
    from: usize,
    clock: &mut usize,
    dfn: &mut [usize],
    low: &mut [usize],
    stk: &mut Vec<usize>,
    instk: &mut [bool],
    scc: &mut [usize],
    scc_size: &mut Vec<usize>,
) {
    dfn[cur] = *clock;
    low[cur] = *clock;
    stk.push(cur);
    instk[cur] = true;
    *clock += 1;
    for &next in &adj[cur] {
        if next == from {
            continue;
        }
        if dfn[next] == usize::MAX {
            tarjan(adj, next, cur, clock, dfn, low, stk, instk, scc, scc_size);
            low[cur] = low[cur].min(low[next]);
        } else if instk[next] {
            low[cur] = low[cur].min(dfn[next]);
        }
    }
    if dfn[cur] == low[cur] {
        let scc_id = scc_size.len();
        let mut sz = 0;
        while let Some(node) = stk.pop() {
            instk[node] = false;
            sz += 1;
            scc[node] = scc_id;
            if node == cur {
                break;
            }
        }
        scc_size.push(sz);
    }
}
