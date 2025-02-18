//! core logic only
//! submission: https://codeforces.com/contest/1677/submission/283838240
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let ca: Vec<usize> = scanner.iter(n).collect();
    let mut perm = vec![0; n];
    for (i, &p) in scanner.iter::<usize>(n).zip(&ca) {
        perm[p - 1] = i - 1;
    }
    let mut vis = vec![false; n];
    let mut cnt = 0;
    for mut i in 0..n {
        if vis[i] {
            continue;
        }
        let mut c = 0;
        while !vis[i] {
            vis[i] = true;
            c += 1;
            i = perm[i];
        }
        cnt += c / 2;
    }
    (n - cnt) * cnt * 2
}
