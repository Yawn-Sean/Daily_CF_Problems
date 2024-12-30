// core logic only
// submission: https://codeforces.com/problemset/submission/900/262282032
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut count = vec![0; n + 1];
    let (mut mx, mut mx2) = (0, 0);
    for x in scanner.iter::<usize>(n) {
        if mx > x && mx2 < x {
            count[mx] += 1;
        }
        if x > mx {
            count[x] -= 1;
            mx2 = mx;
            mx = x;
        } else if x > mx2 {
            mx2 = x;
        }
    }
    (1..=n).rev().max_by_key(|&i| count[i]).unwrap()
}
