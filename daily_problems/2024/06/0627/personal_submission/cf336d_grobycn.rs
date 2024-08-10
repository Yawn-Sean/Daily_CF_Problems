// core logic only
// submission: https://codeforces.com/problemset/submission/366/267665470
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, edges: Vec<(usize, usize, u32, u32)>) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for &(a, b, l, r) in &edges {
        adj[a - 1].push((b - 1, l, r));
        adj[b - 1].push((a - 1, l, r));
    }

    fn dijkstra(adj: &[Vec<(usize, u32, u32)>], lowest: u32) -> Option<u32> {
        use std::collections::BinaryHeap;
        let n = adj.len();
        let mut hp = BinaryHeap::from([(u32::MAX, 0)]);
        let mut upper = vec![0; n];
        upper[0] = u32::MAX;
        while let Some((u, cur)) = hp.pop() {
            if cur == n - 1 {
                return Some(u + 1 - lowest);
            }
            if upper[cur] < u {
                continue;
            }
            for &(next, l, r) in &adj[cur] {
                if l > lowest || r < lowest {
                    continue;
                }
                let u = u.min(r);
                if upper[next] >= u {
                    continue;
                }
                upper[next] = u;
                hp.push((u, next));
            }
        }
        None
    }

    edges
        .iter()
        .filter_map(|&(_, _, lowest, _)| dijkstra(&adj, lowest))
        .max()
        .ok_or("Nice work, Dima!")
}
