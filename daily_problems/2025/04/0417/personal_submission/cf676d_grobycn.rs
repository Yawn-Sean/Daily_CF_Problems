//! core logic only
//! submission: https://codeforces.com/problemset/submission/676/315969744
const MULTIPLE_TEST: bool = false;

const TOP: u8 = 0b1000;
const RIGHT: u8 = 0b0100;
const BOTTOM: u8 = 0b0010;
const LEFT: u8 = 0b0001;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mp: Vec<_> = scanner
        .iter(n)
        .map(String::into_bytes)
        .map(|mut row| {
            row.iter_mut().for_each(|c| {
                *c = match *c {
                    b'+' => LEFT | RIGHT | BOTTOM | TOP,
                    b'-' => LEFT | RIGHT,
                    b'|' => TOP | BOTTOM,
                    b'^' => TOP,
                    b'>' => RIGHT,
                    b'<' => LEFT,
                    b'v' => BOTTOM,
                    b'L' => RIGHT | TOP | BOTTOM,
                    b'R' => LEFT | TOP | BOTTOM,
                    b'U' => BOTTOM | LEFT | RIGHT,
                    b'D' => TOP | LEFT | RIGHT,
                    _ => 0,
                }
            });
            row
        })
        .collect();

    let rotate = |inital_state: u8, rot_time: usize| {
        ((inital_state >> rot_time) | (inital_state << (4 - rot_time))) & 0b1111
    };

    let mut dist = vec![vec![[usize::MAX; 4]; m]; n];
    let (mut xt, mut yt) = <(usize, usize)>::from_scanner(scanner);
    let (mut xm, mut ym) = <(usize, usize)>::from_scanner(scanner);
    (xt, yt, xm, ym) = (xt - 1, yt - 1, xm - 1, ym - 1);
    dist[xt][yt][0] = 0;
    let mut queue = std::collections::VecDeque::from([(xt, yt, 0)]);
    while let Some((x, y, mut rot)) = queue.pop_front() {
        let mut d = dist[x][y][rot];
        let door_state = rotate(mp[x][y], rot);
        for (r, c, dir) in [
            (x.wrapping_sub(1), y, TOP),
            (x + 1, y, BOTTOM),
            (x, y.wrapping_sub(1), LEFT),
            (x, y + 1, RIGHT),
        ] {
            if r < n && c < m && door_state & dir != 0 && dist[r][c][rot] == usize::MAX {
                let neighbor_state = rotate(mp[r][c], rot);
                if neighbor_state & rotate(dir, 2) != 0 {
                    dist[r][c][rot] = d + 1;
                    queue.push_back((r, c, rot));
                }
            }
        }
        rot = (rot + 1) % 4;
        if dist[x][y][rot] == usize::MAX {
            dist[x][y][rot] = d + 1;
            queue.push_back((x, y, rot));
        }
    }

    let ans = *dist[xm][ym].iter().min().unwrap();
    if ans == usize::MAX {
        Err(-1)
    } else {
        Ok(ans)
    }
}
