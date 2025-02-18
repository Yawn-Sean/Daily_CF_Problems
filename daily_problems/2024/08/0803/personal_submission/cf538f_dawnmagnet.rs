fn main() {
    input! {n: usize, q: usize, c: usize}
    input! {stars: [(usize, usize, usize); n]}
    input! {queries: [(usize, usize, usize, usize, usize); q]}

    let mut dp = [[[0; 105]; 105]; 15];
    for i in 0..n {
        let (x, y, s) = stars[i];
        dp[0][x][y] += s;
        for j in 1..=c {
            dp[j][x][y] += (s + j) % (c + 1);
        }
    }
    for i in 0..=c {
        for j in 1..105 {
            for k in 1..105 {
                dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k] + dp[i][j][k] - dp[i][j - 1][k - 1];
            }
        }
        // dbg!(dp[i]);
    }
    // println!("{:?}", dp[0]);

    for (t, x1, y1, x2, y2) in queries {
        let t = t % (c + 1);
        println!(
            "{}",
            dp[t][x2][y2] + dp[t][x1 - 1][y1 - 1] - dp[t][x1 - 1][y2] - dp[t][x2][y1 - 1]
        );
    }
}
