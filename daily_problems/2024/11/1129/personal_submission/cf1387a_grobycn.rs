//! core logic only
//! submission: https://codeforces.com/problemset/submission/1387/293833889
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut a, mut b, c) in scanner.iter::<(usize, usize, i64)>(m) {
        (a, b) = (a - 1, b - 1);
        adj[a].push((b, c));
        adj[b].push((a, c));
    }

    let mut ans = vec![0.0; n];
    let mut expr = vec![(i64::MAX, i64::MAX); n];

    for i in 0..n {
        if expr[i].0 != i64::MAX {
            continue;
        }
        expr[i] = (1, 0);
        let mut queue = std::collections::VecDeque::from([i]);
        let mut group = vec![];
        let mut fixed = f64::NAN;
        while let Some(cur) = queue.pop_front() {
            group.push(cur);
            let (k, b) = expr[cur];
            for &(next, c) in &adj[cur] {
                let (u, v) = expr[next];
                if u == i64::MAX {
                    expr[next] = (-k, c - b);
                    queue.push_back(next);
                } else if k + u == 0 {
                    if b + v != c {
                        return Err("NO");
                    }
                } else {
                    let x = ((c - b - v) as f64) / ((k + u) as f64);
                    if fixed.is_nan() {
                        fixed = x;
                    } else if fixed != x {
                        return Err("NO");
                    }
                }
            }
        }
        if fixed.is_nan() {
            let mut xs: Vec<_> = group
                .iter()
                .map(|&i| {
                    let (k, b) = expr[i];
                    -b / k
                })
                .collect();
            xs.sort_unstable();
            fixed = xs[xs.len() / 2] as f64;
        }
        for &i in &group {
            let (x, y) = expr[i];
            ans[i] = (x as f64) * fixed + (y as f64);
        }
    }
    Ok("YES".cr().then(Sep::<_, ' '>(ans)))
}
