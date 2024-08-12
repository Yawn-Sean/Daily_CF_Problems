//! core logic only
//! submission: https://codeforces.com/contest/190/submission/271399442
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashSet;

    let mut forbid = vec![vec![]; n];
    for (mut a, mut b) in scanner.iter::<(usize, usize)>(m) {
        (a, b) = (a - 1, b - 1);
        forbid[a].push(b);
        forbid[b].push(a);
    }
    let mut unvisited: HashSet<_> = (0..n).collect(); 
    let mut ans = vec![];
    while !unvisited.is_empty() {
        let u = *unvisited.iter().next().unwrap();
        unvisited.remove(&u);
        let mut stk = vec![u];
        let mut group = vec![];
        while let Some(cur) = stk.pop() {
            group.push(cur + 1);
            let mut reachable = HashSet::new();
            std::mem::swap(&mut unvisited, &mut reachable);
            for &v in &forbid[cur] {
                if reachable.remove(&v) {
                    unvisited.insert(v);
                }
            }
            for v in reachable {
                stk.push(v);
            }
        }
        ans.push(group);
    }
    ans.len().cr()
        .then(Sep::<_, '\n'>(
            ans.into_iter().map(|group| (group.len(), Sep::<_, ' '>(group)))
        ))
}
