// core logic only
// submission: https://codeforces.com/contest/243/submission/271045174
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, h: usize, t: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashSet;
    let mut edges = Vec::with_capacity(m);
    let mut adj = vec![HashSet::new(); n];
    for (mut a, mut b) in scanner.iter::<(usize, usize)>(m) {
        (a, b) = (a - 1, b - 1);
        adj[a].insert(b);
        adj[b].insert(a);
        edges.push((a, b));
    }

    for &(a, b) in &edges {
        for (u, v) in [(a, b), (b, a)] {
            if adj[u].len() <= h || adj[v].len() <= t {
                continue;
            }
            let both = adj[u].iter().filter(|&i| adj[v].contains(i)).count();
            if adj[u].len() + adj[v].len() - both >= h + t + 2 {
                let mut head: Vec<_> = adj[u].iter()
                    .copied()
                    .filter(|&i| i != v && !adj[v].contains(&i))
                    .take(h)
                    .map(|i| i + 1)
                    .collect();
                let mut tail: Vec<_> = adj[v].iter()
                    .copied()
                    .filter(|&i| i != u && !adj[u].contains(&i))
                    .take(t)
                    .map(|i| i + 1)
                    .collect();
                for &i in adj[u].iter().filter(|&i| adj[v].contains(i)) {
                    if head.len() < h {
                        head.push(i + 1);
                    } else if tail.len() < t {
                        tail.push(i + 1);
                    } else {
                        break;
                    }
                }
                return Ok("YES".cr().then((u + 1, v + 1))
                    .cr().then(Sep::<_, ' '>(head))
                    .cr().then(Sep::<_, ' '>(tail)));
            }
        }
    }
    Err("NO")
}
