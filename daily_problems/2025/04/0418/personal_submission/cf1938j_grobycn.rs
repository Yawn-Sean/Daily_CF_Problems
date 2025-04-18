//! core logic only
//! submission: https://codeforces.com/problemset/submission/1938/316089939
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let edges: Vec<_> = scanner
        .iter::<(usize, usize, usize)>(m)
        .map(|(u, v, t)| (u - 1, v - 1, t))
        .collect();
    for (i, &(u, v, _)) in edges.iter().enumerate() {
        adj[u].push(i);
        adj[v].push(i);
    }

    fn dijkstra(
        adj: &[Vec<usize>],
        edges: &[(usize, usize, usize)],
        src: usize,
    ) -> (Vec<usize>, Vec<usize>) {
        use std::cmp::Reverse;
        use std::collections::BinaryHeap;
        let n = adj.len();
        let mut dist = vec![usize::MAX; n];
        dist[src] = 0;
        let mut route = vec![usize::MAX; n];
        let mut hp = BinaryHeap::new();

        hp.push((Reverse(0), src));
        while let Some((Reverse(d), cur)) = hp.pop() {
            if d > dist[cur] {
                continue;
            }
            for &eidx in &adj[cur] {
                let (u, v, t) = edges[eidx];
                let next = u ^ v ^ cur;
                let d = d + t;
                if dist[next] > d {
                    dist[next] = d;
                    route[next] = eidx;
                    hp.push((Reverse(d), next));
                }
            }
        }

        (dist, route)
    }

    let (dist1, route) = dijkstra(&adj, &edges, 0);
    if dist1[n - 1] == usize::MAX {
        return Err(-1);
    }
    let mut cur = n - 1;
    let mut used = vec![false; m];
    while cur != 0 {
        let eidx = route[cur];
        let (u, v, _) = edges[eidx];
        used[eidx] = true;
        cur ^= u ^ v;
    }

    let mut ans = usize::MAX;
    let (dist2, _) = dijkstra(&adj, &edges, n - 1);
    for (&(u, v, t), used) in edges.iter().zip(used) {
        if used {
            continue;
        }
        let u2v = dist1[u].saturating_add(dist2[v]).saturating_add(t);
        let v2u = dist1[v].saturating_add(dist2[u]).saturating_add(t);
        ans = ans.min(u2v).min(v2u);
    }
    if ans == usize::MAX {
        return Err(-1);
    }
    Ok(ans + dist1[n - 1])
}
