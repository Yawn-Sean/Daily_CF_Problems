//! core logic only
//! submission: https://codeforces.com/problemset/submission/196/273894592
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut maze: Vec<_> = scanner.iter::<String>(n).map(|s| s.into_bytes()).collect();
    let mut vis = vec![vec![(i32::MAX, i32::MAX); m]; n];
    let (mut sx, mut sy) = (0, 0);
    'outer: for (r, row) in maze.iter().enumerate() {
        for (c, &x) in row.iter().enumerate() {
            if x == b'S' {
                (sx, sy) = (r, c);
                break 'outer;
            }
        }
    }

    vis[sx][sy] = (0, 0);
    let mut queue = std::collections::VecDeque::from([(sx, sy, 0, 0)]);
    while let Some((x, y, h, v)) = queue.pop_front() {
        for (r, c, dh, dv) in [
            ((x + n - 1) % n, y, if x == 0 { -1 } else { 0 }, 0),
            ((x + 1) % n, y, if x == n - 1 { 1 } else { 0 }, 0),
            (x, (y + m - 1) % m, 0, if y == 0 { -1 } else { 0 }),
            (x, (y + 1) % m, 0, if y == m - 1 { 1 } else { 0 }),
        ] {
            let (h, v) = (h + dh, v + dv);
            if maze[r][c] == b'#' || vis[r][c] == (h, v) {
                continue;
            }
            if vis[r][c] != (i32::MAX, i32::MAX) {
                return "Yes";
            }
            vis[r][c] = (h, v);
            queue.push_back((r, c, h, v));
        }
    }
    "No"
}
