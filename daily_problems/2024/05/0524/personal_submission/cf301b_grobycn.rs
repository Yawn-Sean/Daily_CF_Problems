// core logic only
// submission: https://codeforces.com/problemset/submission/301/262393977
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, d: i32, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<i32> = [0]
        .into_iter()
        .chain(scanner.iter(n - 2))
        .chain([0])
        .collect();
    let pos: Vec<(i32, i32)> = scanner.iter(n).collect();
    let dist = |src: usize, dst: usize| {
        let (x0, y0) = pos[src];
        let (x1, y1) = pos[dst];
        d * ((x0 - x1).abs() + (y0 - y1).abs()) - a[dst]
    };

    let mut cur = 0;
    let mut d = vec![i32::MAX; n];
    d[0] = 0;
    let mut vis = vec![false; n];
    vis[0] = true;
    while cur != n - 1 {
        let mut choose = 0;
        let mut mn = i32::MAX;
        for next in 0..n {
            if vis[next] {
                continue;
            }
            d[next] = d[next].min(dist(cur, next) + d[cur]);
            if d[next] < mn {
                choose = next;
                mn = d[next];
            }
        }
        vis[choose] = true;
        cur = choose;
    }
    d[n - 1]
}
