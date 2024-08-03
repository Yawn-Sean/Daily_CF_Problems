// core logic only
// submission: https://codeforces.com/problemset/submission/1016/254445590
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut xor = 0;
    let rows: Vec<_> = scanner.iter(n).inspect(|&x: &usize| xor ^= x).collect();
    let cols: Vec<_> = scanner.iter(m).inspect(|&x: &usize| xor ^= x).collect();
    if xor != 0 {
        return Err("NO");
    }
    let mut ans = vec![vec![0; m]; n];
    xor = rows[0];
    for i in 1..m {
        ans[0][i] = cols[i];
        xor ^= cols[i];
    }
    for i in 1..n {
        ans[i][0] = rows[i];
    }
    ans[0][0] = xor;
    Ok("YES".cr().then(Mat(ans)))
}
