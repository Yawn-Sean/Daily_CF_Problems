//! core logic only
//! submission: https://codeforces.com/problemset/submission/761/282926310
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (u, v) in scanner.iter::<(usize, usize)>(n - 1) {
        let (u, v) = (u - 1, v - 1);
        adj[u].push(v);
        adj[v].push(u);
    }

    if adj.iter().any(|nb| nb.len() > 4) {
        return Err("NO");
    }

    let mut ans = vec![(i64::MAX, i64::MAX); n];
    ans[0] = (0, 0);
    let mut queue = std::collections::VecDeque::from([(0, 1 << 40, 4)]);
    let dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)];
    while let Some((cur, dist, from)) = queue.pop_front() {
        let (x, y) = ans[cur];
        let mut ds = (0..4).filter(|&dir| dir != from);
        for &next in &adj[cur] {
            if ans[next].0 == i64::MAX {
                let d = ds.next().unwrap();
                let (dx, dy) = dirs[d];
                ans[next] = (x + dist * dx, y + dist * dy);
                queue.push_back((next, dist >> 1, d ^ 1));
            }
        }
    }

    Ok("YES".cr().then(Sep::<_, '\n'>(ans)))
}
