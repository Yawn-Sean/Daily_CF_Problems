//! core logic only
//! submission: https://codeforces.com/problemset/submission/1252/288508766
const MULTIPLE_TEST: bool = false;

fn solver(mut lands: Vec<(usize, usize)>) -> impl Printable {
    lands.iter_mut().for_each(|(l, w)| {
        if *l > *w {
            std::mem::swap(l, w);
        }
    });
    lands.sort_unstable();
    let mut maxw = 0;
    let mut max_area = 0;
    let mut ans = 0;
    for &(l, w) in lands.iter().rev() {
        max_area = max_area.max(l * w);
        ans = ans.max(l * maxw.min(w));
        maxw = maxw.max(w);
    }
    if ans * 2 >= max_area {
        format!("{}.0", ans)
    } else {
        format!("{}.{}", max_area / 2, (max_area & 1) * 5)
    }
}
