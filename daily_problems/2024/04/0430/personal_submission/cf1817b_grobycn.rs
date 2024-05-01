// core logic only
// submission: https://codeforces.com/contest/1817/submission/258861967
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, mut edges: Vec<(usize, usize)>) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (u, v) in &mut edges {
        *u -= 1;
        *v -= 1;
        adj[*u].push(*v);
        adj[*v].push(*u);
    }

    for &(u, v) in &edges {
        if adj[u].len() < 4 && adj[v].len() < 4 {
            continue;
        }
        let mut from = vec![usize::MAX; n];
        let mut vis = vec![false; n];
        vis[u] = true;
        let mut queue = std::collections::VecDeque::from([u]);
        while let Some(cur) = queue.pop_front() {
            for &next in &adj[cur] {
                if vis[next] || (cur, next) == (u, v) {
                    continue;
                }
                vis[next] = true;
                from[next] = cur;
                if next == v {
                    break;
                }
                queue.push_back(next);
            }
        }
        if vis[v] {
            let mut path = vec![(u + 1, v + 1)];
            let mut cur = v;
            let mut prev = v;
            while cur != u {
                prev = from[cur];
                path.push((prev + 1, cur + 1));
                std::mem::swap(&mut prev, &mut cur);
            }
            if adj[u].len() >= 4 {
                for &next in adj[u]
                    .iter()
                    .filter(|&&next| next != v && next != prev)
                    .take(2)
                {
                    path.push((u + 1, next + 1))
                }
            } else {
                for &next in adj[v]
                    .iter()
                    .filter(|&&next| next != u && next != from[v])
                    .take(2)
                {
                    path.push((v + 1, next + 1));
                }
            }
            return Ok("YES".cr().then(path.len()).cr().then(Sep::<_, '\n'>(path)));
        }
    }
    Err("NO")
}
