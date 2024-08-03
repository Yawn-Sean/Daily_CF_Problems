// core logic only
// submission: https://codeforces.com/contest/1102/submission/256006953
const MULTIPLE_TEST: bool = false;

fn solver(Mat(mat): Mat<i64>) -> impl Printable {
    let (n, m) = (mat.len(), mat[0].len());
    let dist = |row0: &[i64], row1: &[i64]| {
        row0.iter()
            .zip(row1)
            .map(|(x, y)| (x - y).abs())
            .min()
            .unwrap_or(i64::MAX)
    };
    if n == 1 {
        return dist(&mat[0][1..], &mat[0][..m - 1]);
    }

    let mut dist0 = vec![vec![0; n]; n];
    let mut dist1 = vec![vec![0; n]; n];
    for (i, rowi) in mat.iter().enumerate() {
        for (j, rowj) in mat[..i].iter().enumerate() {
            dist0[i][j] = dist(rowi, rowj);
            dist0[j][i] = dist0[i][j];
            dist1[i][j] = dist(&rowi[1..], &rowj[..m - 1]);
            dist1[j][i] = dist(&rowj[1..], &rowi[..m - 1]);
        }
    }

    let mut ans = 0;
    let m = 1 << n;
    for first_row in 0..n {
        dist0.swap(first_row, 0);
        dist0.iter_mut().for_each(|row| row.swap(first_row, 0));
        dist1.swap(first_row, 0);
        dist1.iter_mut().for_each(|row| row.swap(first_row, 0));
        let mut dp = vec![vec![-1; n]; m];
        dp[1][0] = i64::MAX;
        for mask in 0..m / 2 {
            let mask = (mask << 1) | 1;
            for cur in 0..n {
                if mask & (1 << cur) == 0 || dp[mask][cur] == -1 {
                    continue;
                }
                for next in 1..n {
                    if mask & (1 << next) != 0 {
                        continue;
                    }
                    let mut mn = dp[mask][cur].min(dist0[cur][next]);
                    let mask1 = mask | (1 << next);
                    if mask1 + 1 == m {
                        mn = mn.min(dist1[0][next]);
                    }
                    dp[mask1][next] = dp[mask1][next].max(mn);
                }
            }
        }
        ans = ans.max(*dp[m - 1].iter().max().unwrap());
    }
    ans
}
