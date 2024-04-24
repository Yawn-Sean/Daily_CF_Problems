// core logic only
// submission: https://codeforces.com/contest/933/submission/256771102
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let (mut dp1, mut dp12, mut dp121, mut dp1212) = (0, 0, 0, 0);
    for x in scanner.iter::<u8>(n) {
        if x == 1 {
            dp1 += 1;
            dp121 = dp12.max(dp121) + 1;
        } else {
            dp12 = dp1.max(dp12) + 1;
            dp1212 = dp121.max(dp1212) + 1;
        }
    }
    dp1.max(dp12).max(dp121).max(dp1212)
}
