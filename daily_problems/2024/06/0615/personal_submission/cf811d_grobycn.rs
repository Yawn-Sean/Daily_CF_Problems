// core logic only
// submission: https://codeforces.com/problemset/submission/811/265830873
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let maze: Vec<_> = scanner.iter::<String>(n).map(|s| s.into_bytes()).collect();
    let mut vis = vec![vec![false; m]; n];
    let mut pre = vec![vec![(usize::MAX, usize::MAX); m]; n];
    let mut queue = std::collections::VecDeque::from([(0usize, 0usize)]);
    vis[0][0] = true;
    let (mut fx, mut fy) = (0, 0);
    'outer: while let Some((x, y)) = queue.pop_front() {
        for (r, c) in [
            (x.wrapping_sub(1), y),
            (x + 1, y),
            (x, y.wrapping_sub(1)),
            (x, y + 1),
        ] {
            if r < n && c < m && maze[r][c] != b'*' && !vis[r][c] {
                vis[r][c] = true;
                pre[r][c] = (x, y);
                if maze[r][c] == b'F' {
                    (fx, fy) = (r, c);
                    break 'outer;
                }
                queue.push_back((r, c));
            }
        }
    }
    let mut dirs = vec![];
    let (mut x, mut y) = (fx, fy);
    while (x, y) != (0, 0) {
        let (px, py) = pre[x][y];
        if px + 1 == x {
            dirs.push(3);
        } else if x + 1 == px {
            dirs.push(2);
        } else if py + 1 == y {
            dirs.push(1);
        } else {
            dirs.push(0);
        }
        (x, y) = (px, py);
    }
    dirs.reverse();

    let mut press = |btn: char| {
        println!("{btn}");
        <(usize, usize)>::from_scanner(scanner)
    };

    let mut cur = (1, 1);
    let buttons = ['L', 'R', 'U', 'D'];
    let mut rev = [0, 0];
    for btn in dirs {
        let rev = &mut rev[btn >> 1];
        let next = press(buttons[btn ^ *rev]);
        if next == cur {
            *rev ^= 1;
            cur = press(buttons[btn ^ *rev]);
        } else {
            cur = next;
        }
    }
    ""
}
