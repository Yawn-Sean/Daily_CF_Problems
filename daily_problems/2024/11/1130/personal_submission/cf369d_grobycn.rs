//! core logic only
//! submission: https://codeforces.com/problemset/submission/369/293993678
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: u16, scanner: &mut Scanner) -> impl Printable {
    let p: Vec<u8> = scanner.iter(n).collect();
    let mut suf = vec![0; n + 1];
    for i in (0..n).rev() {
        suf[i] = suf[i + 1].max(p[i]);
    }

    let mut dist = vec![vec![u16::MAX; n + 2]; n + 1];
    dist[0][1] = 0;
    let mut queue = std::collections::VecDeque::from([(0, 1, 0)]);
    while let Some((first, second, mut step)) = queue.pop_front() {
        if second >= n {
            continue;
        }
        step += 1;
        if p[first] != 0 && suf[second] != 100 {
            if dist[first][second + 1] > step {
                dist[first][second + 1] = step;
                queue.push_back((first, second + 1, step));
            }
        }
        if p[first] != 100 && suf[second] != 0 {
            if dist[second][second + 1] > step {
                dist[second][second + 1] = step;
                queue.push_back((second, second + 1, step))
            }
        }
        if p[first] != 0 && suf[second] != 0 {
            if dist[second + 1][second + 2] > step {
                dist[second + 1][second + 2] = step;
                queue.push_back((second + 1, second + 2, step));
            }
        }
    }
    dist.into_iter()
        .map(|row| row.into_iter())
        .flatten()
        .filter(|&d| d <= k)
        .count()
}
