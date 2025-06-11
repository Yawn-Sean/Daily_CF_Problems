//! core logic only
//! submission: https://codeforces.com/problemset/submission/550/287378209
const MULTIPLE_TEST: bool = false;

fn solver(k: usize) -> impl Printable {
    if k & 1 == 0 {
        return Err("NO");
    }

    let h = 2 * k - 1;
    let n = h * 2;
    let m = h * k;
    let mut edges = Vec::with_capacity(m);
    edges.push((1, h + 1));
    let mut add_edge = |u: usize, v: usize| {
        edges.push((u, v));
        edges.push((u + h, v + h));
    };
    for upper in (2..).take(k - 1) {
        add_edge(1, upper);
        for lower in (k + 1..).take(k - 1) {
            add_edge(upper, lower);
        }
    }
    for lower in (k + 1..).step_by(2).take((k - 1) / 2) {
        add_edge(lower, lower + 1);
    }
    Ok("YES".cr().then((n, m)).cr().then(Sep::<_, '\n'>(edges)))
}
