//! core logic only
//! submission: https://codeforces.com/problemset/submission/1214/303513730
const MULTIPLE_TEST: bool = false;

fn solver(d: Vec<usize>) -> impl Printable {
    let n = d.len();
    let mut indices = vec![vec![]; n];
    for (i, &di) in d.iter().enumerate() {
        indices[di - 1].push(i);
    }
    let mut sorted: Vec<_> = indices
        .iter()
        .rev()
        .map(|r| r.iter())
        .flatten()
        .copied()
        .collect();
    let mut ans = Vec::with_capacity(2 * n - 1);
    for w in sorted.windows(2) {
        ans.push((2 * w[0] + 1, 2 * w[1] + 1));
    }
    for i in 0..n {
        let cur = sorted[i];
        let r = i + d[cur] - 1;
        if r + 1 == sorted.len() {
            sorted.push(cur);
        }
        let mut endpoint = 2 * sorted[r] + 1;
        if r >= n {
            endpoint += 1;
        }
        ans.push((endpoint, 2 * cur + 2));
    }
    Sep::<_, '\n'>(ans)
}
