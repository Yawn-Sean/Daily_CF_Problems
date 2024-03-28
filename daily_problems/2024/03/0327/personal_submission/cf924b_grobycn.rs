// core logic only
// submission: https://codeforces.com/problemset/submission/924/253480173
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, u: u32, scanner: &mut Scanner) -> impl Printable {
    let es: Vec<u32> = scanner.iter(n).collect();
    let mut ans = -1.0f64;
    let mut r = 0;
    for (l, &e) in es.iter().enumerate() {
        while r < n && es[r] - e <= u {
            r += 1;
        }
        if r - l >= 3 {
            ans = ans.max(((es[r - 1] - es[l + 1]) as f64) / ((es[r - 1] - e) as f64));
        }
    }
    format!("{ans}")
}
