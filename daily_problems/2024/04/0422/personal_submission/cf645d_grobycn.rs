// core logic only
// submission: https://codeforces.com/contest/645/submission/257745311
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, edges: Vec<(usize, usize)>) -> impl Printable {
    let check = |k: usize| {
        let mut deg = vec![0; n];
        let mut adj = vec![vec![]; n];
        for &(u, v) in &edges[..k] {
            let (u, v) = (u - 1, v - 1);
            deg[v] += 1;
            adj[u].push(v);
        }
        let mut queue: Vec<_> = (0..n).filter(|&i| deg[i] == 0).collect();
        if queue.len() > 1 {
            return false;
        }
        while let Some(cur) = queue.pop() {
            for &next in &adj[cur] {
                deg[next] -= 1;
                if deg[next] == 0 {
                    queue.push(next);
                }
            }
            if queue.len() > 1 {
                return false;
            }
        }
        true
    };

    let m = edges.len();
    let (mut lo, mut hi) = (1, m + 1);
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        if check(mid) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if hi == m + 1 {
        Err(-1)
    } else {
        Ok(hi)
    }
}
