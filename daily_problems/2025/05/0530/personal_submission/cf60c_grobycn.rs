//! core logic only
//! submission: https://codeforces.com/problemset/submission/60/322067863
const MULTIPLE_TEST: bool = false;

fn gcd(mut a: usize, mut b: usize) -> usize {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}

fn dfs(adj: &[Vec<(usize, usize, usize)>], cur: usize, xs: &mut [usize]) -> bool {
    if xs[cur] == 0 {
        return false;
    }
    for &(next, g, l) in &adj[cur] {
        if xs[next] == usize::MAX {
            xs[next] = g * l / xs[cur];
            if !dfs(adj, next, xs) {
                return false;
            }
        }
        if xs[next] * xs[cur] != g * l || gcd(xs[cur], xs[next]) != g {
            return false;
        }
    }
    true
}

fn reset(adj: &[Vec<(usize, usize, usize)>], cur: usize, xs: &mut [usize]) {
    xs[cur] = usize::MAX;
    for &(next, _, _) in &adj[cur] {
        if xs[next] != usize::MAX {
            reset(adj, next, xs);
        }
    }
}

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut u, mut v, g, l) in scanner.iter::<(usize, usize, usize, usize)>(m) {
        (u, v) = (u - 1, v - 1);
        adj[u].push((v, g, l));
        adj[v].push((u, g, l));
    }

    let mut ans = vec![usize::MAX; n];
    for i in 0..n {
        if ans[i] != usize::MAX {
            continue;
        }
        if adj[i].is_empty() {
            ans[i] = 1;
            continue;
        }
        let mut mx = 0;
        for &(_, _, l) in adj[i].iter() {
            mx = gcd(mx, l);
        }
        for x in 1..=1000.min(mx) {
            if mx % x != 0 {
                continue;
            }
            ans[i] = x;
            if dfs(&adj, i, &mut ans) {
                break;
            }
            reset(&adj, i, &mut ans);
            ans[i] = mx / x;
            if dfs(&adj, i, &mut ans) {
                break;
            }
            reset(&adj, i, &mut ans);
        }
        if ans[i] == usize::MAX {
            return Err("NO");
        }
    }
    Ok("YES".cr().then(Sep::<_, ' '>(ans)))
}
