fn main() {
    input! { n: usize, m: usize }
    input! { v: [String; n] }
    let v = v
        .into_iter()
        .map(|s| s.as_bytes().to_vec())
        .collect::<Vec<_>>();
    let mut vis = vec![vec![None; m]; n];
    let mut q = VecDeque::new();
    for i in 0..n {
        for j in 0..m {
            if v[i][j] == b'S' {
                q.push_back((i as i32, j as i32));
                vis[i][j] = Some((i as i32, j as i32));
            }
        }
    }
    let n = n as i32;
    let m = m as i32;
    while let Some((x, y)) = q.pop_front() {
        for (dx, dy) in [(-1, 0), (1, 0), (0, -1), (0, 1)] {
            let (rx, ry) = (x + dx, y + dy);
            let nx = (((rx) % n + n) % n) as usize;
            let ny = (((ry) % m + m) % m) as usize;
            if v[nx][ny] == b'#' {
                continue;
            }
            if vis[nx][ny].is_none() {
                vis[nx][ny] = Some((rx, ry));
                q.push_back((rx, ry));
            } else if Some((rx, ry)) != vis[nx][ny] {
                println!("Yes");
                return;
            }
        }
    }
    println!("No");
}
