//! core logic only
//! submission: https://codeforces.com/problemset/submission/82/297246833
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<u32>) -> impl Printable {
    let n = a.len();
    let mut dp = vec![vec![0; n + 1]; n];
    let mut keep = vec![vec![0u8; n + 1]; n];
    for (i, &ai) in a.iter().enumerate() {
        dp[i][n] = ai;
        dp[i][n - 1] = ai.max(a[n - 1]);
    }
    for (i, &ai) in a[..n - 1].iter().enumerate().rev() {
        for (j, &aj) in a[..i].iter().enumerate().rev() {
            let cost1 = dp[j][i + 2] + ai.max(a[i + 1]);
            let cost2 = dp[i][i + 2] + aj.max(a[i + 1]);
            let cost3 = dp[i + 1][i + 2] + aj.max(ai);
            let mn = cost1.min(cost2).min(cost3);
            dp[j][i] = mn;
            if mn == cost1 {
                keep[j][i] = 1;
            } else if mn == cost2 {
                keep[j][i] = 2;
            } else {
                keep[j][i] = 3;
            }
        }
    }

    let cost = dp[0][1];
    let mut serve_order = Vec::with_capacity((n + 1) / 2);
    let (mut first, mut second) = (0, 1);
    while second < n {
        match keep[first][second] {
            1 => {
                serve_order.push(vec![second + 1, second + 2]);
            }
            2 => {
                serve_order.push(vec![first + 1, second + 2]);
                first = second;
            }
            _ => {
                serve_order.push(vec![first + 1, second + 1]);
                first = second + 1;
            }
        }
        second += 2;
    }
    if first < n {
        serve_order.push(vec![first + 1]);
    }
    cost.cr()
        .then(Sep::<_, '\n'>(serve_order.into_iter().map(Sep::<_, ' '>)))
}
