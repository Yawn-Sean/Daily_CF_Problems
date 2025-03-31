//! core logic only
//! submission: https://codeforces.com/problemset/submission/847/313251979
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, q: usize, p: usize, scanner: &mut Scanner) -> impl Printable {
    let map: Vec<_> = scanner.iter(n).map(String::into_bytes).collect();
    let mut noise = vec![vec![0; m]; n];
    let mut vis = vec![vec![0; m]; n];
    let mut count = 0;
    for (r, row) in map.iter().enumerate() {
        for (c, &b) in row.iter().enumerate() {
            if b == b'.' || b == b'*' {
                continue;
            }
            let mut q = ((b + 1 - b'A') as usize) * q;
            count += 1;
            vis[r][c] = count;
            let mut queue = vec![(r, c)];
            while q > 0 && !queue.is_empty() {
                let mut next_queue = vec![];
                for (r, c) in queue {
                    noise[r][c] += q;
                    for (i, j) in [
                        (r.wrapping_sub(1), c),
                        (r + 1, c),
                        (r, c.wrapping_sub(1)),
                        (r, c + 1),
                    ] {
                        if i < n && j < m && vis[i][j] != count && map[i][j] != b'*' {
                            vis[i][j] = count;
                            next_queue.push((i, j));
                        }
                    }
                }
                queue = next_queue;
                q >>= 1;
            }
        }
    }
    noise.iter().flat_map(|r| r).filter(|&l| *l > p).count()
}
