//! core logic only
//! submission: https://codeforces.com/problemset/submission/1105/273345188
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, s: Vec<usize>, scanner: &mut Scanner) -> impl Printable {
    let mut grid: Vec<_> = scanner
        .iter::<String>(n)
        .map(|row| row.into_bytes())
        .collect();
    let p = s.len();
    let mut ans = vec![0; p];
    let mut queues = vec![vec![]; p];
    for (r, row) in grid.iter().enumerate() {
        for (c, &x) in row.iter().enumerate() {
            match x {
                b'1'..=b'9' => {
                    let idx = (x - b'1') as usize;
                    queues[idx].push((r, c));
                    ans[idx] += 1;
                }
                _ => {}
            }
        }
    }

    loop {
        let mut empty_queue_cont = 0;
        for ((q, &s), cnt) in queues.iter_mut().zip(&s).zip(&mut ans) {
            for _ in 0..s {
                let cells = std::mem::replace(q, vec![]);
                for (r, c) in cells {
                    for (i, j) in [
                        (r.wrapping_sub(1), c),
                        (r + 1, c),
                        (r, c.wrapping_sub(1)),
                        (r, c + 1),
                    ] {
                        if i < n && j < m && grid[i][j] == b'.' {
                            grid[i][j] = b'#';
                            *cnt += 1;
                            q.push((i, j));
                        }
                    }
                }
                if q.is_empty() {
                    empty_queue_cont += 1;
                    break;
                }
            }
        }
        if empty_queue_cont == p {
            return Sep::<_, ' '>(ans);
        }
    }
}
