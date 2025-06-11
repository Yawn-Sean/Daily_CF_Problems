// core logic only
// submission: https://codeforces.com/problemset/submission/666/265495254
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let mut rev = vec![vec![]; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(m) {
        (u, v) = (u - 1, v - 1);
        adj[u].push(v);
        rev[v].push(u);
    }

    fn bfs(adj: &[Vec<usize>], src: usize) -> Vec<usize> {
        let n = adj.len();
        let mut dist = vec![usize::MAX; n];
        let mut queue = std::collections::VecDeque::from([src]);
        dist[src] = 0;

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

    fn best3(xs: &[usize], src: usize) -> [usize; 3] {
        let mut ret = [src; 3];
        for (i, &x) in xs.iter().enumerate() {
            if x == usize::MAX {
                continue;
            }
            if x > xs[ret[0]] {
                ret[2] = ret[1];
                ret[1] = ret[0];
                ret[0] = i;
            } else if x > xs[ret[1]] {
                ret[2] = ret[1];
                ret[1] = i;
            } else if x > xs[ret[2]] {
                ret[2] = i;
            }
        }
        ret
    }

    let dist1 = (0..n).map(|i| bfs(&adj, i)).collect::<Vec<_>>();
    let best1 = dist1
        .iter()
        .enumerate()
        .map(|(i, xs)| best3(xs, i))
        .collect::<Vec<_>>();
    let dist2 = (0..n).map(|i| bfs(&rev, i)).collect::<Vec<_>>();
    let best2 = dist2
        .iter()
        .enumerate()
        .map(|(i, xs)| best3(xs, i))
        .collect::<Vec<_>>();

    let mut mx = 0;
    let mut ans = (0, 0, 0, 0);
    for second in 0..n {
        for third in 0..n {
            if second == third || dist1[second][third] == usize::MAX {
                continue;
            }
            for first in best2[second] {
                if first == second || first == third || dist2[second][first] == usize::MAX {
                    continue;
                }
                for forth in best1[third] {
                    if forth == first
                        || forth == second
                        || forth == third
                        || dist1[third][forth] == usize::MAX
                    {
                        continue;
                    }
                    let d = dist1[second][third] + dist2[second][first] + dist1[third][forth];
                    if d > mx {
                        mx = d;
                        ans = (first + 1, second + 1, third + 1, forth + 1);
                    }
                }
            }
        }
    }
    ans
}
