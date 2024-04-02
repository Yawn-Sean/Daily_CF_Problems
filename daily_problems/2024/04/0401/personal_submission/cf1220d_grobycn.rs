// core logic only
// submission: https://codeforces.com/contest/1220/submission/254448763
const MULTIPLE_TEST: bool = false;

fn solver(xs: Vec<usize>) -> impl Printable {
    let mut count = std::collections::HashMap::new();
    for &x in &xs {
        *count.entry((x & !(x - 1)).trailing_zeros()).or_insert(0) += 1;
    }
    if count.len() == 0 {
        return Err(0);
    }
    let mxkey = *count.keys().max_by_key(|k| count[k]).unwrap();
    let cnt = xs.len() - count[&mxkey];
    let ans = xs
        .into_iter()
        .filter(move |x| (x & !(x - 1)).trailing_zeros() != mxkey);
    Ok(cnt.cr().then(Sep::<_, ' '>(ans)))
}
