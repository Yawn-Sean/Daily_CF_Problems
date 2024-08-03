// core logic only
// submission: https://codeforces.com/contest/662/submission/257294128
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut u, mut v, c) in scanner.iter::<(usize, usize, char)>(m) {
        u -= 1;
        v -= 1;
        let c = u8::from(c == 'R');
        adj[u].push((v, c));
        adj[v].push((u, c));
    }

    fn dfs(
        adj: &[Vec<(usize, u8)>],
        cur: usize,
        fa: usize,
        color: u8,
        ops: &mut [u8],
        opcnt: &mut usize,
        vertices: &mut Vec<usize>,
    ) -> bool {
        vertices.push(cur);
        let rev = ops[cur];
        for &(next, c) in &adj[cur] {
            if next == fa {
                continue;
            }
            if ops[next] == u8::MAX {
                let op = u8::from(c ^ rev != color);
                ops[next] = op;
                *opcnt += op as usize;
                if !dfs(adj, next, cur, color, ops, opcnt, vertices) {
                    return false;
                }
            } else if c ^ rev ^ ops[next] != color {
                return false;
            }
        }
        true
    }

    let mut ans = usize::MAX;
    let mut operations = vec![];
    'outter: for color in [0, 1] {
        let mut ops = vec![u8::MAX; n];
        let mut total_opcnt = 0;
        for i in 0..n {
            if ops[i] != u8::MAX {
                continue;
            }
            let mut vertices = vec![];
            let mut opcnt = 0;
            ops[i] = 0;
            if dfs(&adj, i, i, color, &mut ops, &mut opcnt, &mut vertices) {
                if opcnt * 2 > vertices.len() {
                    vertices.iter().for_each(|&i| ops[i] ^= 1);
                    opcnt = vertices.len() - opcnt;
                }
                total_opcnt += opcnt;
            } else {
                continue 'outter;
            }
        }
        if total_opcnt < ans {
            ans = total_opcnt;
            operations = ops;
        }
    }

    if ans == usize::MAX {
        return Err(-1);
    }
    Ok(ans.cr().then(Sep::<_, ' '>(
        (1..=n).filter(move |&i| operations[i - 1] == 1),
    )))
}
