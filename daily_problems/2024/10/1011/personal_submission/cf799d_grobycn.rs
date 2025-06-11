//! core logic only
//! submission: https://codeforces.com/problemset/submission/799/285311082
const MULTIPLE_TEST: bool = false;

fn solver(a: usize, b: usize, h: usize, w: usize, mut extensions: Vec<usize>) -> impl Printable {
    fn solve(x: usize, y: usize, exts: &[usize]) -> usize {
        use std::collections::HashMap;
        let mut vis = HashMap::new();
        vis.insert((x, y), 0);

        for &m in exts {
            let keys: Vec<_> = vis.keys().copied().collect();
            for (x, y) in keys {
                let c = vis[&(x, y)];
                let nx = (x + m - 1) / m;
                if !vis.contains_key(&(nx, y)) {
                    vis.insert((nx, y), c + 1);
                }
                let ny = (y + m - 1) / m;
                if !vis.contains_key(&(x, ny)) {
                    vis.insert((x, ny), c + 1);
                }
            }
        }
        *vis.get(&(1, 1)).unwrap_or(&usize::MAX)
    }

    extensions.sort_unstable_by_key(|&x| std::cmp::Reverse(x));
    let exts = if extensions.len() > 34 {
        &extensions[..34]
    } else {
        &extensions
    };
    let ans =
        solve(a.div_ceil(h), b.div_ceil(w), exts).min(solve(a.div_ceil(w), b.div_ceil(h), exts));
    if ans == usize::MAX {
        Err(-1)
    } else {
        Ok(ans)
    }
}
