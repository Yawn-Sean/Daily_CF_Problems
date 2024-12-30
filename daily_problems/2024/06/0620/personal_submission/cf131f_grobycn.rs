// core logic only
// submission: https://codeforces.com/problemset/submission/131/266964367
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    if n < 3 || m < 3 {
        return 0;
    }

    let mut sky: Vec<_> = scanner.iter::<String>(n).map(|s| s.into_bytes()).collect();
    let mut stars = vec![vec![0; m]; n];
    for i in 1..n - 1 {
        for j in 1..m - 1 {
            if sky[i][j] == b'1'
                && sky[i - 1][j] == b'1'
                && sky[i + 1][j] == b'1'
                && sky[i][j - 1] == b'1'
                && sky[i][j + 1] == b'1'
            {
                stars[i][j] = 1;
            }
            stars[i][j] += stars[i][j - 1];
        }
        stars[i][m - 1] = stars[i][m - 2];
    }

    let mut ans = 0;
    for l in 0..m - 1 {
        for r in l + 1..m {
            let stars: Vec<_> = (0..n).map(|i| stars[i][r - 1] - stars[i][l]).collect();
            let mut u = 0;
            let mut sum = 0;
            for d in 0..n - 1 {
                sum += stars[d];
                while sum >= k {
                    sum -= stars[u];
                    u += 1;
                }
                if u > 0 {
                    ans += u - 1;
                }
            }
        }
    }
    ans
}
