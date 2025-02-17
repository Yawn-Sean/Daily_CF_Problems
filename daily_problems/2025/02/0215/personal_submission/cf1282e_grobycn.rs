//! core logic only
//! submission: https://codeforces.com/problemset/submission/1282/306343572
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::{HashMap, HashSet, VecDeque};
    let mut edge_owner = HashMap::new();
    let mut triangles = Vec::with_capacity(n - 2);

    for (i, (a, b, c)) in scanner.iter::<(usize, usize, usize)>(n - 2).enumerate() {
        let mut abc = [a, b, c];
        abc.sort_unstable();
        let [a, b, c] = abc;
        edge_owner.entry((a, b)).or_insert(HashSet::new()).insert(i);
        edge_owner.entry((a, c)).or_insert(HashSet::new()).insert(i);
        edge_owner.entry((b, c)).or_insert(HashSet::new()).insert(i);
        triangles.push(abc);
    }

    let mut adj = vec![vec![]; n];
    for (&(u, v), owners) in edge_owner.iter() {
        if owners.len() == 1 {
            adj[u - 1].push(v - 1);
            adj[v - 1].push(u - 1);
        }
    }

    let mut p = Vec::with_capacity(n);
    let mut cur = 0;
    let mut pre = 0;
    while p.len() < n {
        p.push(cur + 1);
        for &next in &adj[cur] {
            if next != pre {
                pre = cur;
                cur = next;
                break;
            }
        }
    }

    let is_outer = |edge_owner: &HashMap<(usize, usize), HashSet<usize>>,
                    &[a, b, c]: &[usize; 3]| {
        let c1 = edge_owner.get(&(a, b)).map(|o| o.len()).unwrap_or(0);
        let c2 = edge_owner.get(&(a, c)).map(|o| o.len()).unwrap_or(0);
        let c3 = edge_owner.get(&(b, c)).map(|o| o.len()).unwrap_or(0);
        (c1 == 1 && c2 == 1) || (c1 == 1 && c3 == 1) || (c2 == 1 && c3 == 1)
    };

    let mut q = Vec::with_capacity(n - 2);
    let mut queue = VecDeque::new();
    for (i, tri) in triangles.iter().enumerate() {
        if is_outer(&edge_owner, tri) {
            q.push(i + 1);
            queue.push_back(i);
        }
    }

    while q.len() < n - 2 {
        let cur = queue.pop_front().unwrap();
        let [a, b, c] = triangles[cur];
        let mut revealed = None;
        for e in [(a, b), (a, c), (b, c)] {
            if let Some(owners) = edge_owner.get_mut(&e) {
                owners.remove(&cur);
                if owners.len() == 1 {
                    revealed = owners.iter().next().copied();
                }
            }
        }
        if let Some(i) = revealed {
            if is_outer(&edge_owner, &triangles[i]) {
                q.push(i + 1);
                queue.push_back(i);
            }
        }
    }
    Sep::<_, ' '>(p).cr().then(Sep::<_, ' '>(q))
}
