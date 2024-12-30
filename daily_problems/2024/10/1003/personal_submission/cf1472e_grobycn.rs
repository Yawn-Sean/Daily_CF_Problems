//! core logic only
//! submission: https://codeforces.com/problemset/submission/1472/284110587
const MULTIPLE_TEST: bool = true;

fn solver(friends: Vec<(usize, usize)>) -> impl Printable {
    let n = friends.len();
    let mut sort0: Vec<_> = (0..n).collect();
    let mut sort1 = sort0.clone();
    sort0.sort_unstable_by_key(|&i| friends[i].0);
    sort1.sort_unstable_by_key(|&i| friends[i].1);

    let mut ans = vec![-1; n];
    let mut iter0 = sort0.iter().peekable();
    let mut iter1 = sort1.iter().peekable();
    let mut minw = usize::MAX;
    let mut minw_at = usize::MAX;
    let mut minh = usize::MAX;
    let mut minh_at = usize::MAX;
    for &i in sort0.iter() {
        let (h, w) = friends[i];
        while let Some(&j) = iter0.next_if(|&&j| friends[j].0 < h) {
            if minw > friends[j].1 {
                minw = friends[j].1;
                minw_at = j;
            }
        }
        while let Some(&j) = iter1.next_if(|&&j| friends[j].1 < h) {
            if minh > friends[j].0 {
                minh = friends[j].0;
                minh_at = j;
            }
        }
        if minw < w {
            ans[i] = minw_at as i32 + 1;
        } else if minh < w {
            ans[i] = minh_at as i32 + 1;
        }
    }
    Sep::<_, ' '>(ans)
}
