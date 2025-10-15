//! core logic only
//! submission: https://codeforces.com/problemset/submission/1612/293511512
const MULTIPLE_TEST: bool = false;

fn solver(mut stu: Vec<(usize, usize)>) -> impl Printable {
    use std::cmp::Reverse;
    use std::collections::HashMap;

    let mut max_exp = (0, 1); // rational number 0 / 1
    let mut ans = vec![];
    for pinned in 1..=20 {
        let mut sum = HashMap::new();
        for &(mi, ki) in &stu {
            *sum.entry(mi).or_insert(0) += ki.min(pinned);
        }
        let mut sum: Vec<_> = sum.into_iter().collect();
        sum.sort_unstable_by_key(|&(_, ksum)| Reverse(ksum));
        let exp = sum
            .iter()
            .map(|&(_, ksum)| ksum)
            .take(pinned)
            .sum::<usize>();
        if max_exp.0 * pinned < exp * max_exp.1 {
            max_exp = (exp, pinned);
            ans = sum.iter().map(|&(m, _)| m).take(pinned).collect();
        }
    }
    ans.len().cr().then(Sep::<_, ' '>(ans))
}
