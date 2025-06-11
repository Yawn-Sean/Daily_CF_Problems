//! core logic only
//! submission: https://codeforces.com/problemset/submission/386/313879252
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, v0: usize, v1: usize, v2: usize, scanner: &mut Scanner) -> impl Printable {
    let mat: Vec<_> = scanner.iter(n).map(String::into_bytes).collect();
    let mut vs = [v0 - 1, v1 - 1, v2 - 1];
    vs.sort_unstable();
    let mut queue = std::collections::VecDeque::from([vs]);
    let mut dist = vec![vec![vec![usize::MAX; n]; n]; n];
    let mut prev = vec![vec![vec![[usize::MAX; 3]; n]; n]; n];
    let mut path = vec![vec![vec![(usize::MAX, usize::MAX); n]; n]; n];
    dist[vs[0]][vs[1]][vs[2]] = 0;

    while let Some([v0, v1, v2]) = queue.pop_front() {
        let sum = v0 + v1 + v2;
        if sum == 3 {
            break;
        }
        let step = dist[v0][v1][v2];
        for v in 0..n {
            if v == v0 || v == v1 || v == v2 {
                continue;
            }
            for (fix0, fix1) in [(v0, v1), (v0, v2), (v1, v2)] {
                let tomove = sum - fix0 - fix1;
                if mat[v][tomove] == mat[fix0][fix1] {
                    let mut vs = [v, fix0, fix1];
                    vs.sort_unstable();
                    if dist[vs[0]][vs[1]][vs[2]] == usize::MAX {
                        dist[vs[0]][vs[1]][vs[2]] = step + 1;
                        prev[vs[0]][vs[1]][vs[2]] = [v0, v1, v2];
                        path[vs[0]][vs[1]][vs[2]] = (tomove + 1, v + 1);
                        queue.push_back(vs);
                    }
                }
            }
        }
    }
    let step = dist[0][1][2];
    if step == usize::MAX {
        return Err(-1);
    }
    let mut moves = Vec::with_capacity(step);
    let [mut v0, mut v1, mut v2] = [0, 1, 2];
    for _ in 0..step {
        moves.push(path[v0][v1][v2]);
        [v0, v1, v2] = prev[v0][v1][v2];
    }
    Ok(moves
        .len()
        .cr()
        .then(Sep::<_, '\n'>(moves.into_iter().rev())))
}
