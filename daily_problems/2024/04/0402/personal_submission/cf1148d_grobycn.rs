// core logic only
// submission: https://codeforces.com/contest/1148/submission/254714953
const MULTIPLE_TEST: bool = false;

fn solver(pairs: Vec<(i32, i32)>) -> impl Printable {
    let n = pairs.len();
    let ltcnt = pairs.iter().filter(|(a, b)| a < b).count();
    let ans = if 2 * ltcnt > n {
        let mut indices: Vec<_> = (0..n).filter(|&i| pairs[i].0 < pairs[i].1).collect();
        indices.sort_unstable_by_key(|&i| -pairs[i].1);
        indices
    } else {
        let mut indices: Vec<_> = (0..n).filter(|&i| pairs[i].0 > pairs[i].1).collect();
        indices.sort_unstable_by_key(|&i| pairs[i].0);
        indices
    };
    ans.len()
        .cr()
        .then(Sep::<_, ' '>(ans.into_iter().map(|x| x + 1)))
}
