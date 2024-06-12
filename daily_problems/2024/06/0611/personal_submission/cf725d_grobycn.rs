// core logic only
// submission: https://codeforces.com/problemset/submission/725/265206303
const MULTIPLE_TEST: bool = false;

fn solver(mut teams: Vec<(usize, usize)>) -> impl Printable {
    use std::cmp::Reverse;
    use std::collections::BinaryHeap;

    let mut t = teams[0].0;
    teams[1..].sort_unstable_by_key(|&(t, _)| Reverse(t));
    let mut hp: BinaryHeap<_> = teams[1..]
        .iter()
        .take_while(|&&(ti, _)| ti > t)
        .map(|&(t, w)| Reverse(w - t + 1))
        .collect();
    let mut ans = hp.len() + 1;
    let mut rest = teams[ans..].iter().peekable();
    while let Some(Reverse(d)) = hp.pop() {
        if t < d {
            break;
        }
        t -= d;
        while let Some(&(t, w)) = rest.next_if(|&&(ti, _)| ti > t) {
            hp.push(Reverse(w - t + 1));
        }
        ans = ans.min(hp.len() + 1);
    }
    ans
}
