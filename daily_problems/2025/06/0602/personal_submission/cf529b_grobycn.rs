//! core logic only
//! submission: https://codeforces.com/problemset/submission/529/322549689
const MULTIPLE_TEST: bool = false;

fn solver(mut rect: Vec<(usize, usize)>) -> impl Printable {
    let n = rect.len();
    let mut ans = usize::MAX;
    rect.sort_unstable_by_key(|&(w, h)| w.saturating_sub(h));
    'outer: for maxh in 1..=1000 {
        let mut wsum = 0;
        let mut cnt = 0;
        let mut delta = vec![];
        for &(w, h) in rect.iter() {
            match (w > maxh, h > maxh) {
                (true, true) => continue 'outer,
                (true, false) => wsum += w,
                (false, true) => {
                    cnt += 1;
                    wsum += h;
                }
                (false, false) => {
                    wsum += w;
                    delta.push(w.saturating_sub(h));
                }
            }
        }
        if cnt > n / 2 {
            continue;
        }
        let rest = n / 2 - cnt;
        if rest > 0 {
            wsum -= delta.iter().rev().take(rest).sum::<usize>();
        }
        ans = ans.min(wsum * maxh);
    }
    ans
}
