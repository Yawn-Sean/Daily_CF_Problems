//! core logic only
//! submission: https://codeforces.com/problemset/submission/515/288900273
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    const SYMBOLS: [u8; 4] = [b'<', b'^', b'>', b'v'];
    const DIRECTIONS: [usize; 5] = [1, 2, 1, 0, 1];

    fn find_direction(grid: &[Vec<u8>], r: usize, c: usize) -> Option<usize> {
        let (n, m) = (grid.len(), grid[0].len());
        let mut ret = None;
        for (i, delta) in DIRECTIONS.windows(2).enumerate() {
            let (dr, dc) = (delta[0], delta[1]);
            let r = (r + dr).wrapping_sub(1);
            let c = (c + dc).wrapping_sub(1);
            if r < n && c < m && grid[r][c] == b'.' {
                if ret.is_some() {
                    return None;
                }
                ret = Some(i);
            }
        }
        ret
    }

    let mut grid: Vec<_> = scanner.iter::<String>(n).map(|s| s.into_bytes()).collect();
    let mut queue = std::collections::VecDeque::new();
    let mut empty = 0;
    for (r, row) in grid.iter().enumerate() {
        for (c, &x) in row.iter().enumerate() {
            if x == b'.' {
                empty += 1;
                if let Some(dir) = find_direction(&grid, r, c) {
                    queue.push_back((r, c, dir));
                }
            }
        }
    }
    while let Some((r, c, dir)) = queue.pop_front() {
        if grid[r][c] != b'.' {
            continue;
        }
        empty -= 2;
        grid[r][c] = SYMBOLS[dir];
        let r = (r + DIRECTIONS[dir]).saturating_sub(1);
        let c = (c + DIRECTIONS[dir + 1]).saturating_sub(1);
        grid[r][c] = SYMBOLS[dir ^ 2];
        for delta in DIRECTIONS.windows(2) {
            let (dr, dc) = (delta[0], delta[1]);
            let r = (r + dr).wrapping_sub(1);
            let c = (c + dc).wrapping_sub(1);
            if r < n && c < m && grid[r][c] == b'.' {
                if let Some(dir) = find_direction(&grid, r, c) {
                    queue.push_back((r, c, dir));
                }
            }
        }
    }
    if empty != 0 {
        Err("Not unique")
    } else {
        Ok(Sep::<_, '\n'>(
            grid.into_iter()
                .map(|row| unsafe { String::from_utf8_unchecked(row) }),
        ))
    }
}
