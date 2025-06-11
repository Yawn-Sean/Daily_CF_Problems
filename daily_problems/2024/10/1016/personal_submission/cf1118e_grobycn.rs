//! core logic only
//! submission: https://codeforces.com/contest/1118/submission/286231925
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize) -> impl Printable {
    if k * (k - 1) < n {
        return Err("NO");
    }
    let ans = (1..=k - 1)
        .map(move |b| (b + 1..=k).map(move |g| [(b, g), (g, b)]).flatten())
        .flatten()
        .take(n);
    Ok("YES".cr().then(Sep::<_, '\n'>(ans)))
}
