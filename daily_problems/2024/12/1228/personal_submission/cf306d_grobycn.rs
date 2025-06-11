//! core logic only
//! submission: https://codeforces.com/problemset/submission/306/298946880
const MULTIPLE_TEST: bool = false;

fn solver(n: usize) -> impl Printable {
    use std::f64::consts::PI;
    if n <= 4 {
        return Err("No solution");
    }
    let (mut x, mut y) = (0.0, 0.0);
    let theta = 2.0 * PI / (n as f64);
    let mut ans = Vec::with_capacity(n);
    let epsilon = 0.01;
    ans.push((0.0, 0.0));
    for i in 1..n - 1 {
        let len = 500.0 + (i as f64) * epsilon;
        let theta = theta * (i as f64);
        x += len * theta.cos();
        y += len * theta.sin();
        ans.push((x, y));
    }
    let theta = ((n - 1) as f64) * theta;
    // dy = len * sin(theta)
    let len = -y / theta.sin();
    x += len * theta.cos();
    ans.push((x, 0.0));
    Ok(Sep::<_, '\n'>(ans))
}
