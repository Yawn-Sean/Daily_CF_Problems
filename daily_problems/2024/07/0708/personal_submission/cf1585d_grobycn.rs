// core logic only
// submission: https://codeforces.com/problemset/submission/1585/269579810
const MULTIPLE_TEST: bool = true;

fn solver(a: Vec<usize>) -> impl Printable {
    let n = a.len();
    let mut vis = vec![false; n];
    for &i in &a {
        let i = i - 1;
        if vis[i] {
            return "YES";
        }
        vis[i] = true;
    }

    let mut parity = n & 1;
    for mut i in 0..n {
        if !vis[i] {
            continue;
        }
        while vis[i] {
            vis[i] = false;
            i = a[i] - 1;
        }
        parity ^= 1;
    }

    if parity == 0 {
        "YES"
    } else {
        "NO"
    }
}
