// core logic only
// submission: https://codeforces.com/problemset/submission/954/261067984
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<i32>) -> impl Printable {
    let mut deltas: std::collections::HashSet<_> =
        a.windows(2).map(|w| (w[0] - w[1]).abs()).collect();
    if deltas.contains(&0) {
        return Err("NO");
    }
    let (x, y) = match deltas.len() {
        0 => (1, a[0]),
        1 => (1_000_000_000, deltas.into_iter().next().unwrap()),
        2 => match deltas.remove(&1) {
            true => (1_000_000_000, deltas.into_iter().next().unwrap()),
            _ => return Err("NO"),
        },
        _ => return Err("NO"),
    };
    if a.windows(2).all(|w| {
        let (i0, j0) = ((w[0] - 1) / y, (w[0] - 1) % y);
        let (i1, j1) = ((w[1] - 1) / y, (w[1] - 1) % y);
        (i0 - i1).abs() + (j0 - j1).abs() == 1
    }) {
        Ok("YES".cr().then((x, y)))
    } else {
        Err("NO")
    }
}
