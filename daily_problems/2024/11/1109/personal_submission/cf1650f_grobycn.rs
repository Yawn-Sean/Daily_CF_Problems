//! core logic only
//! submission: https://codeforces.com/problemset/submission/1650/290648829
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let mut g = vec![vec![]; n];

    for ((e, t, p), i) in scanner.iter::<(usize, usize, usize)>(m).zip(1..) {
        g[e - 1].push((t, p, i));
    }

    let mut t = 0;
    let mut ans = vec![];
    for (&ai, gi) in a.iter().zip(&g) {
        let m = gi.len();
        let mut dp = vec![usize::MAX / 2; 101];
        let mut from = vec![vec![usize::MAX; m]; 101];
        dp[0] = 0;
        for (idx, &(t, p, i)) in gi.iter().enumerate() {
            for x in (0..=100).rev() {
                let y = (x + p).min(100);
                if dp[y] > dp[x] + t {
                    dp[y] = dp[x] + t;
                    from[y][idx] = x;
                }
            }
        }
        t += dp[100];
        if t > ai {
            return Err(-1);
        }
        let mut cur = 100;
        for i in (0..m).rev() {
            if from[cur][i] != usize::MAX {
                cur = from[cur][i];
                ans.push(gi[i].2);
            }
        }
    }
    Ok(ans.len().cr().then(Sep::<_, ' '>(ans)))
}
