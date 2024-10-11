//! core logic only
//! submission: https://codeforces.com/problemset/submission/1031/279485804
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mat: Vec<_> = scanner.iter::<String>(n).map(|s| s.into_bytes()).collect();
    let mut dp = vec![vec![usize::MAX; n + 1]; n + 1];
    dp[0][1] = 0;
    for (i, row) in mat.iter().enumerate() {
        for (j, &x) in row.iter().enumerate() {
            dp[i + 1][j + 1] = dp[i + 1][j].min(dp[i][j + 1]) + usize::from(x != b'a');
        }
    }
    let mut mx = 0;
    let mut queue = vec![(0, 0)];
    for i in 1..=n {
        for j in 1..=n {
            if dp[i][j] <= k {
                let d = i + j - 1;
                if d > mx {
                    mx = d;
                    queue = vec![(i - 1, j - 1)];
                } else if d == mx {
                    queue.push((i - 1, j - 1));
                }
            }
        }
    }

    let mut ans = Vec::with_capacity(2 * n - 1);
    if mx == 0 {
        ans.push(mat[0][0]);
    } else {
        ans.extend(std::iter::repeat(b'a').take(mx));
    }
    let mut vis = vec![vec![false; n]; n];
    while !queue.is_empty() {
        let mut nq = vec![];
        let mut mn = b'z' + 1;
        for (i, j) in queue {
            for (r, c) in [(i + 1, j), (i, j + 1)] {
                if r < n && c < n && !vis[r][c] {
                    vis[r][c] = true;
                    if mat[r][c] < mn {
                        mn = mat[r][c];
                        nq = vec![(r, c)];
                    } else if mat[r][c] == mn {
                        nq.push((r, c));
                    }
                }
            }
        }
        if mn <= b'z' {
            ans.push(mn);
        }
        queue = nq;
    }

    unsafe { String::from_utf8_unchecked(ans) }
}
