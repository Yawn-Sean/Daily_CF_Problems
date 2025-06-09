//! core logic only
//! submission: https://codeforces.com/problemset/submission/1090/314019623
const MULTIPLE_TEST: bool = false;

#[rustfmt::skip]
const DIRS: [(i32, i32); 8] = [
    (-2, -1), (-2, 1), (2, -1), (2, 1),
    (-1, -2), (-1, 2), (1, -2), (1, 2),
];

fn chessboard_index(idx: usize) -> String {
    let idx = idx as u8;
    let (r, c) = (idx / 8, idx % 8);
    format!("{}{}", (c + b'a') as char, (r + b'1') as char)
}

fn solver(k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut state: u64 = 0;
    for cell in scanner.iter::<String>(k) {
        let cell = cell.as_bytes();
        let col = cell[0] - b'a';
        let row = cell[1] - b'1';
        state |= 1 << (row * 8 + col);
    }
    let mut ans = vec![];
    for src in k..64 {
        if state & (1 << src) == 0 {
            continue;
        }
        let dst = (state + 1).trailing_zeros() as usize;
        let mut prev = [usize::MAX; 64];
        prev[dst] -= 1;
        let mut queue = std::collections::VecDeque::from([dst]);
        while let Some(cur) = queue.pop_front() {
            let (x, y) = (cur / 8, cur % 8);
            for (dx, dy) in DIRS {
                let (x, y) = (x as i32 + dx, y as i32 + dy);
                if 0 <= x && x < 8 && 0 <= y && y < 8 {
                    let next = (x * 8 + y) as usize;
                    if prev[next] == usize::MAX {
                        prev[next] = cur;
                        queue.push_back(next);
                    }
                }
            }
        }
        let mut knights = vec![src];
        while let Some(&cur) = knights.last() {
            let pre = prev[cur];
            if pre + 1 == usize::MAX {
                break;
            }
            if state & (1 << pre) == 0 {
                let mut to = pre;
                while let Some(from) = knights.pop() {
                    state ^= 1 << from;
                    state ^= 1 << to;
                    ans.push([chessboard_index(from), chessboard_index(to)]);
                    to = from;
                }
            }
            knights.push(pre);
        }
    }

    ans.len()
        .cr()
        .then(Sep::<_, '\n'>(ans.into_iter().map(Sep::<_, '-'>)))
}
