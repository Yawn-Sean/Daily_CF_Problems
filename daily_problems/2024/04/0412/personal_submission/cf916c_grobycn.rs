// core logic only
// submission: https://codeforces.com/contest/916/submission/256230562
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize) -> impl Printable {
    const PRIME: usize = 998_244_353;

    let mst_edges = (1..n - 1)
        .map(|i| (i, i + 1, 1))
        .chain([(n - 1, n, PRIME - (n - 2))]);

    let rest_edges = (1..n - 1)
        .map(move |u| (u + 2..=n).map(move |v| (u, v, PRIME + 1)))
        .flatten()
        .take(m - (n - 1));

    (PRIME, PRIME)
        .cr()
        .then(Sep::<_, '\n'>(mst_edges.chain(rest_edges)))
}
