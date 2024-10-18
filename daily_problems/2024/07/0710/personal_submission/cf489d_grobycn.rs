// core logic only
// submission: https://codeforces.com/problemset/submission/489/269740824
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (u, v) in scanner.iter::<(usize, usize)>(m) {
        adj[u - 1].push(v - 1);
    }

    let mut ans = 0;
    for a in 0..n {
        let mut count = vec![0; n];
        for &u in &adj[a] {
            for &v in &adj[u] {
                count[v] += 1;
            }
        }
        for c in 0..n {
            if c == a || count[c] <= 1 {
                continue;
            }
            ans += count[c] * (count[c] - 1) / 2;
        }
    }
    ans
}
