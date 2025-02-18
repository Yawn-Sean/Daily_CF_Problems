//! core logic only
//! submission: https://codeforces.com/problemset/submission/873/279487151
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize) -> impl Printable {
    fn merge_sort_undo(ans: &mut [usize], mut k: usize) -> usize {
        k -= 1;
        if k <= 1 || ans.len() <= 1 {
            return k;
        }
        let m = ans.len() / 2;
        ans.swap(m - 1, m);
        let k = merge_sort_undo(&mut ans[..m], k - 1);
        merge_sort_undo(&mut ans[m..], k + 1)
    }

    let mut ans: Vec<_> = (1..=n).collect();
    if merge_sort_undo(&mut ans, k) != 0 {
        Err(-1)
    } else {
        Ok(Sep::<_, ' '>(ans))
    }
}
