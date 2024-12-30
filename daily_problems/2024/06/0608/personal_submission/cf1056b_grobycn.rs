// core logic only
// submission: https://codeforces.com/contest/1056/submission/264663306
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize) -> impl Printable {
    let mut count = vec![n / m; m];
    for r in 1..=n % m {
        count[r] += 1;
    }
    let mut ans = 0;
    for (ri, &ci) in count.iter().enumerate() {
        for (rj, &cj) in count.iter().enumerate() {
            if (ri * ri + rj * rj) % m == 0 {
                ans += ci * cj;
            }
        }
    }
    ans
}
