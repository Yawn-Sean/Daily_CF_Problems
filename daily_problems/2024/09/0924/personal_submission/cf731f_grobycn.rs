//! core logic only
//! submission: https://codeforces.com/problemset/submission/731/282782826
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    const MAXA: usize = 200_000;
    let mut count = vec![0; MAXA + 1];
    for x in scanner.iter::<usize>(n) {
        count[x] += 1;
    }
    for i in 1..=MAXA {
        count[i] += count[i - 1];
    }
    let range_sum = |l: usize, r: usize| count[r] - count[l - 1];

    let mut ans = 0;
    for i in (1..=MAXA).filter(|&i| count[i] != count[i - 1]) {
        let mut sum = 0;
        for l in (i..=MAXA).step_by(i) {
            let r = (l + i - 1).min(MAXA);
            sum += l * range_sum(l, r);
        }
        ans = ans.max(sum);
    }
    ans
}
