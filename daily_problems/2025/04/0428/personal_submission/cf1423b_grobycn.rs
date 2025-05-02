//! core logic only
//! submission: https://codeforces.com/problemset/submission/1423/317891187
const MULTIPLE_TEST: bool = false;

fn bfs(adj: &[Vec<usize>], pairu: &[usize], pairv: &[usize], dist: &mut [usize]) -> bool {
    let mut queue = std::collections::VecDeque::new();
    for (u, &v) in pairu.iter().enumerate() {
        if v == usize::MAX {
            queue.push_back(u);
            dist[u] = 0;
        } else {
            dist[u] = usize::MAX;
        }
    }

    while let Some(u) = queue.pop_front() {
        for &v in &adj[u] {
            let nu = pairv[v];
            if nu == usize::MAX {
                return true;
            }
            if dist[nu] == usize::MAX {
                dist[nu] = dist[u] + 1;
                queue.push_back(nu);
            }
        }
    }
    false
}

fn dfs(
    adj: &[Vec<usize>],
    u: usize,
    pairu: &mut [usize],
    pairv: &mut [usize],
    dist: &mut [usize],
) -> bool {
    for &v in &adj[u] {
        let nu = pairv[v];
        if nu == usize::MAX || (dist[nu] == dist[u] + 1 && dfs(adj, nu, pairu, pairv, dist)) {
            pairu[u] = v;
            pairv[v] = u;
            return true;
        }
    }
    dist[u] = usize::MAX;
    false
}

fn solver(n: usize, mut edges: Vec<(usize, usize, usize)>) -> impl Printable {
    let m = edges.len();
    if n > m {
        return Err(-1);
    }

    edges.sort_unstable_by_key(|e| e.2);
    let check = |cnt: usize| {
        let mut adj = vec![vec![]; n];
        for &(u, v, _) in &edges[..cnt] {
            adj[u - 1].push(v - 1);
        }
        let mut pairu = vec![usize::MAX; n];
        let mut pairv = vec![usize::MAX; n];
        let mut dist = vec![usize::MAX; n];
        let mut pair_cnt = 0;
        while bfs(&adj, &pairu, &pairv, &mut dist) {
            for u in 0..n {
                if pairu[u] == usize::MAX && dfs(&adj, u, &mut pairu, &mut pairv, &mut dist) {
                    pair_cnt += 1;
                }
            }
        }
        pair_cnt == n
    };

    let (mut lo, mut hi) = (n, m + 1);
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        if check(mid) {
            hi = mid
        } else {
            lo = mid + 1;
        }
    }
    if hi > m {
        return Err(-1);
    }
    Ok(edges[hi - 1].2)
}
