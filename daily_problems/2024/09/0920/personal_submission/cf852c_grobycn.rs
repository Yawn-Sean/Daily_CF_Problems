//! core logic only
//! submission: https://codeforces.com/problemset/submission/852/281997762
const MULTIPLE_TEST: bool = false;

fn solver(b: Vec<usize>) -> impl Printable {
    // maximize \sum_i (b_i + b_{(i + 1) % n}) perm_i
    // sort by b_i + b_{(i + 1) % n}
    let n = b.len();
    let mut indices = vec![vec![]; n * 2];
    indices[b[0] + b[n - 1]].push(n - 1);
    for (i, w) in b.windows(2).enumerate() {
        indices[w[0] +w[1]].push(i);
    }
    let mut ans = vec![0; n];
    indices.into_iter()
        .map(|idx| idx.into_iter())
        .flatten()
        .enumerate()
        .for_each(|(x, i)| ans[i] = x);
    Sep::<_, ' '>(ans)
}
