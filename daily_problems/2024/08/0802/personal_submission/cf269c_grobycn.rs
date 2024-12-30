//! core logic only
//! submission: https://codeforces.com/problemset/submission/269/274017243
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, mut edges: Vec<(usize, usize, usize)>) -> impl Printable {
    let mut flow = vec![0; n];
    let mut adj = vec![vec![]; n];
    for (i, (a, b, c)) in edges.iter_mut().enumerate() {
        *a -= 1;
        *b -= 1;
        flow[*a] += *c;
        flow[*b] += *c;
        adj[*a].push((i, 0));
        adj[*b].push((i, 1));
    }

    flow[1..n - 1].iter_mut().for_each(|f| *f >>= 1);
    let m = edges.len();
    let mut ans = vec![u8::MAX; m];
    let mut queue = std::collections::VecDeque::from([0]);
    while let Some(cur) = queue.pop_front() {
        for &(eidx, dir) in &adj[cur] {
            if ans[eidx] != u8::MAX {
                continue;
            }
            let (a, b, c) = edges[eidx];
            let next = a ^ b ^ cur;
            ans[eidx] = dir;
            flow[next] -= c;
            if flow[next] == 0 {
                queue.push_back(next);
            }
        }
    }
    Sep::<_, '\n'>(ans)
}
