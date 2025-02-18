//! core logic only
//! submission: https://codeforces.com/problemset/submission/756/285107951
const MULTIPLE_TEST: bool = false;

fn solver(perm: Vec<usize>, scanner: &mut Scanner) -> impl Printable {
    let n = perm.len();
    let mut group_cnt = 0;
    let mut vis = vec![false; n];
    for mut i in 0..n {
        if vis[i] {
            continue;
        }
        group_cnt += 1;
        while !vis[i] {
            vis[i] = true;
            i = perm[i] - 1;
        }
    }

    let mut ans = if group_cnt == 1 { 0 } else { group_cnt };
    ans += 1 - (scanner.iter(n).filter(|x: &u8| *x == 1).count() & 1);
    ans
}
