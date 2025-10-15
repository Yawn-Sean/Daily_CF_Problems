//! core logic only
//! submission: https://codeforces.com/problemset/submission/1044/300991309
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::{HashSet, VecDeque};

    let mut adj = vec![vec![]; n];
    for (mut a, mut b) in scanner.iter::<(usize, usize)>(n - 1) {
        (a, b) = (a - 1, b - 1);
        adj[a].push(b);
        adj[b].push(a);
    }
    let k1 = usize::from_scanner(scanner);
    let set1: HashSet<usize> = scanner.iter(k1).collect();
    let k2 = usize::from_scanner(scanner);
    let set2: HashSet<usize> = scanner.iter(k2).collect();
    let mut y = *set2.iter().next().unwrap();
    println!("B {y}");
    let mut x = usize::from_scanner(scanner);
    if set1.contains(&x) {
        return Flush(('C', Ok(x)).cr());
    }

    let mut queue = VecDeque::from([x - 1]);
    let mut vis = vec![false; n];
    vis[x - 1] = true;
    while let Some(cur) = queue.pop_front() {
        if set1.contains(&(cur + 1)) {
            x = cur + 1;
            break;
        }
        for &next in &adj[cur] {
            if set1.contains(&(next + 1)) {}
            if !vis[next] {
                vis[next] = true;
                queue.push_back(next);
            }
        }
    }
    println!("A {x}");
    y = usize::from_scanner(scanner);
    Flush(if set2.contains(&y) {
        ('C', Ok(x)).cr()
    } else {
        ('C', Err(-1)).cr()
    })
}
