// core logic only
// submission: https://codeforces.com/problemset/submission/1029/258248132
const MULTIPLE_TEST: bool = false;

fn solver(segs: Vec<(usize, usize)>) -> impl Printable {
    let n = segs.len();
    let mut intersect = Vec::with_capacity(n);
    let (mut l, mut r) = (0, usize::MAX);
    for &(li, ri) in &segs {
        l = l.max(li);
        r = r.min(ri);
        intersect.push((l, r));
    }
    let mut ans = 0;
    (l, r) = (0, usize::MAX);
    for (i, &(li, ri)) in segs.iter().enumerate().rev() {
        if i > 0 {
            let l = l.max(intersect[i - 1].0);
            let r = r.min(intersect[i - 1].1);
            let cnt = r.saturating_sub(l);
            ans = ans.max(cnt);
        } else {
            ans = ans.max(r.saturating_sub(l));
        }
        l = l.max(li);
        r = r.min(ri);
    }
    ans
}
