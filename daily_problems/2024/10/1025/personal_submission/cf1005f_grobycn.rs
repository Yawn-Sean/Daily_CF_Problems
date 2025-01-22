//! core logic only
//! submission: https://codeforces.com/problemset/submission/1005/287935653
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let edges: Vec<(usize, usize)> = scanner.iter(m).collect();
    for (i, &(a, b)) in edges.iter().enumerate() {
        let (a, b) = (a - 1, b - 1);
        adj[a].push(i);
        adj[b].push(i);
    }

    let mut dist = vec![usize::MAX; n];
    dist[0] = 0;
    let mut queue = std::collections::VecDeque::from([0]);
    while let Some(cur) = queue.pop_front() {
        for &eidx in &adj[cur] {
            let (a, b) = edges[eidx];
            let next = (a - 1) ^ (b - 1) ^ cur;
            if dist[next] != usize::MAX {
                continue;
            }
            dist[next] = dist[cur] + 1;
            queue.push_back(next);
        }
    }

    fn backtrack(
        adj: &[Vec<usize>],
        edges: &[(usize, usize)],
        dist: &[usize],
        idx: usize,
        option: &mut [u8],
        ans: &mut Vec<String>,
    ) -> bool {
        if idx == adj.len() {
            ans.push(unsafe { String::from_utf8_unchecked(option.to_vec()) });
            return ans.len() == ans.capacity();
        }
        for &eidx in &adj[idx] {
            let (a, b) = edges[eidx];
            let prev = (a - 1) ^ (b - 1) ^ idx;
            if dist[prev] + 1 == dist[idx] {
                option[eidx] = b'1';
                if backtrack(adj, edges, dist, idx + 1, option, ans) {
                    return true;
                }
                option[eidx] = b'0';
            }
        }
        false
    }

    let mut ans = Vec::with_capacity(k);
    let mut option = vec![b'0'; m];
    backtrack(&adj, &edges, &dist, 1, &mut option, &mut ans);
    ans.len().cr().then(Sep::<_, '\n'>(ans))
}
