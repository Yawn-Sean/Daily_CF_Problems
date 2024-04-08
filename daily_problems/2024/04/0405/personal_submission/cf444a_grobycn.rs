// core logic only
// submission: https://codeforces.com/problemset/submission/444/255490908
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let v: Vec<u32> = scanner.iter(n).collect();
    let mut ans = 0.0f64;

    for (a, b, c) in scanner.iter::<(usize, usize, u32)>(m) {
        let rho = ((v[a - 1] + v[b - 1]) as f64) / (c as f64);
        ans = ans.max(rho);
    }

    format!("{}", ans)
}
