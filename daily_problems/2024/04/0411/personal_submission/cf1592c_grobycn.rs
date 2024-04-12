// core logic only
// submission: https://codeforces.com/problemset/submission/1592/256119751
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let mut adj = vec![vec![]; n];
    for (u, v) in scanner.iter::<(usize, usize)>(n - 1) {
        adj[u - 1].push(v - 1);
        adj[v - 1].push(u - 1);
    }
    let xor = a.iter().fold(0, |acc, &x| acc ^ x);
    if xor == 0 {
        return "YES";
    }
    if k == 2 {
        return "NO";
    }

    fn dfs(
        adj: &[Vec<usize>],
        cur: usize,
        fa: usize,
        xor: usize,
        a: &[usize],
        cnt: &mut usize,
    ) -> usize {
        let mut ret = a[cur];
        for &next in &adj[cur] {
            if next == fa {
                continue;
            }
            ret ^= dfs(adj, next, cur, xor, a, cnt);
        }
        if ret == xor {
            *cnt += 1;
            return 0;
        }
        ret
    }

    let mut cnt = 0;
    dfs(&adj, 0, 0, xor, &a, &mut cnt);
    if cnt > 1 {
        "YES"
    } else {
        "NO"
    }
}
