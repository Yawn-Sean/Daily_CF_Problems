//! core logic only
//! submission: https://codeforces.com/problemset/submission/909/309760886
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut deg = vec![0; n];
    let mut adj = vec![vec![]; n];
    let e: Vec<usize> = scanner.iter(n).collect();
    for (t1, t2) in scanner.iter::<(usize, usize)>(m) {
        adj[t2].push(t1);
        deg[t1] += 1;
    }

    let mut stk = vec![vec![]; 2];
    for (i, (&ei, &di)) in e.iter().zip(&deg).enumerate() {
        if di == 0 {
            stk[ei].push(i);
        }
    }

    let mut ans = 0;
    while !stk[0].is_empty() || !stk[1].is_empty() {
        while let Some(i) = stk[0].pop() {
            for &next in &adj[i] {
                deg[next] -= 1;
                if deg[next] == 0 {
                    stk[e[next]].push(next);
                }
            }
        }
        if !stk[1].is_empty() {
            ans += 1;
        }
        while let Some(i) = stk[1].pop() {
            for &next in &adj[i] {
                deg[next] -= 1;
                if deg[next] == 0 {
                    stk[e[next]].push(next);
                }
            }
        }
    }
    ans
}
