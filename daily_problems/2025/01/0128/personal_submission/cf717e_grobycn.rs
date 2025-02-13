//! core logic only
//! submission: https://codeforces.com/problemset/submission/717/303350267
const MULTIPLE_TEST: bool = false;

fn solver(mut colors: Vec<i8>, scanner: &mut Scanner) -> impl Printable {
    let n = colors.len();
    let mut adj = vec![vec![]; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(n - 1) {
        (u, v) = (u - 1, v - 1);
        adj[u].push(v);
        adj[v].push(u);
    }

    let mut path = vec![];
    dfs(&adj, 0, 0, &mut colors, &mut path);
    if colors[0] == 1 {
        path.pop();
    }
    Sep::<_, ' '>(path)
}

fn dfs(adj: &[Vec<usize>], cur: usize, fa: usize, colors: &mut [i8], path: &mut Vec<usize>) {
    colors[cur] *= -1;
    path.push(cur + 1);
    for &next in &adj[cur] {
        if next == fa {
            continue;
        }
        dfs(adj, next, cur, colors, path);
        colors[cur] *= -1;
        path.push(cur + 1);
        if colors[next] == -1 {
            colors[next] = 1;
            path.push(next + 1);
            colors[cur] *= -1;
            path.push(cur + 1);
        }
    }
}
