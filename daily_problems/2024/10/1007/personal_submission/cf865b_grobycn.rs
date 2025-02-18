//! core logic only
//! submission: https://codeforces.com/problemset/submission/865/284769989
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, s: i64, scanner: &mut Scanner) -> impl Printable {
    let mut contestants: Vec<(i64, i64, i64)> = scanner.iter(n).collect();
    contestants.sort_unstable_by_key(|c| c.1 - c.2);
    let (mut slice_a, mut happiness_a) = (0, 0);
    for &(si, ai, _) in &contestants {
        slice_a += si;
        happiness_a += si * ai;
    }
    let (mut slice_b, mut happiness_b) = (0, 0);
    let pizza_num = (slice_a + s - 1) / s;
    let mut ans = 0;
    for (si, ai, bi) in contestants {
        slice_a -= si;
        happiness_a -= si * ai;
        let mut cnt_a = (slice_a + s - 1) / s;
        let mut cnt_b = (slice_b + s - 1) / s;
        let undetermined = pizza_num - cnt_a - cnt_b;
        if undetermined >= 0 {
            let (rest_a, rest_b) = (cnt_a * s - slice_a, cnt_b * s - slice_b);
            let (sa, sb) = if bi > ai {
                let sb = (rest_b + undetermined * s).min(si);
                (si - sb, sb)
            } else {
                let sa = (rest_a + undetermined * s).min(si);
                (sa, si - sa)
            };
            let happiness = happiness_a + happiness_b + sa * ai + sb * bi;
            ans = ans.max(happiness);
        }
        slice_b += si;
        happiness_b += si * bi;
    }
    ans
}
