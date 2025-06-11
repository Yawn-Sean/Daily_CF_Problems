//! core logic only
//! submission: https://codeforces.com/problemset/submission/1067/290100998
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::VecDeque;

    if n < 4 {
        return "No";
    }

    let mut adj = vec![vec![]; n];
    let mut deg = vec![0; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(n - 1) {
        (u, v) = (u - 1, v - 1);
        adj[u].push(v);
        adj[v].push(u);
        deg[u] += 1;
        deg[v] += 1;
    }

    fn bfs(adj: &[Vec<usize>], src: usize) -> Vec<usize> {
        let n = adj.len();
        let mut dist = vec![usize::MAX; n];
        dist[src] = 0;
        let mut queue = VecDeque::from([src]);
        while let Some(cur) = queue.pop_front() {
            for &next in &adj[cur] {
                if dist[next] == usize::MAX {
                    dist[next] = dist[cur] + 1;
                    queue.push_back(next);
                }
            }
        }
        dist
    }

    let Some(leaf1) = deg.iter().position(|&d| d == 1) else {
        return "No";
    };
    let dist1 = bfs(&adj, leaf1);
    let mx = *dist1.iter().max().unwrap();
    let leaf2 = dist1.iter().position(|&d| d == mx).unwrap();
    let dist2 = bfs(&adj, leaf2);
    let Some(center) = dist1
        .iter()
        .zip(&dist2)
        .position(|(&d1, &d2)| d1 == k && d2 == k)
    else {
        return "No";
    };

    if deg[center] < 3 {
        return "No";
    }

    let mut queue = VecDeque::from([(center, 0)]);
    deg[center] = 0;
    while let Some((cur, mut dep)) = queue.pop_front() {
        dep += 1;
        for &next in &adj[cur] {
            if deg[next] != 0 {
                if (dep < k && deg[next] < 4) || (dep == k && deg[next] != 1) {
                    return "No";
                }
                deg[next] = 0;
                queue.push_back((next, dep));
            }
        }
    }
    "Yes"
}
