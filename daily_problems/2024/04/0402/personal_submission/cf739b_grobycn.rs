// core logic only
// submission: https://codeforces.com/problemset/submission/739/254717269
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<i64>, scanner: &mut Scanner) -> impl Printable {
    let n = a.len();
    let mut adj = vec![vec![]; n];
    for ((p, w), c) in scanner.iter::<(usize, i64)>(n - 1).zip(1..) {
        adj[p - 1].push((c, w));
    }

    enum Dfs {
        Enter(usize, i64),
        Exit(usize, usize),
    }

    let mut ans = vec![0; n];
    let mut path = vec![];
    let mut stack = vec![Dfs::Exit(0, usize::MAX), Dfs::Enter(0, 0)];
    while let Some(event) = stack.pop() {
        match event {
            Dfs::Enter(cur, dist) => {
                path.push((cur, dist));
                for &(next, w) in &adj[cur] {
                    let dist = dist + w;
                    let mind = dist - a[next];
                    let idx = path.partition_point(|&(_, d)| d < mind);
                    if idx > 0 {
                        ans[path[idx - 1].0] -= 1;
                    }
                    ans[cur] += 1;
                    stack.push(Dfs::Exit(next, cur));
                    stack.push(Dfs::Enter(next, dist));
                }
            }
            Dfs::Exit(cur, parent) => {
                path.pop();
                if parent != usize::MAX {
                    ans[parent] += ans[cur];
                }
            }
        }
    }

    Sep::<_, ' '>(ans)
}
