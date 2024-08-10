// core logic only
// submission: https://codeforces.com/problemset/submission/833/267524605
const MULTIPLE_TEST: bool = true;

fn solver(a: usize, b: usize) -> impl Printable {
    let c = ((a * b) as f64).cbrt().floor() as usize;
    for r in [c, c + 1] {
        if r * r * r == a * b && a % r == 0 && b % r == 0 {
            return "Yes";
        }
    }
    "NO"
}
