//! core logic only
//! submission: https://codeforces.com/problemset/submission/542/310247583
const MULTIPLE_TEST: bool = false;

fn solver(f: Vec<usize>) -> impl Printable {
    let n = f.len();
    let mut cycle_len = 1;
    let mut at_least = 0;
    for mut i in 0..n {
        let mut vis = vec![usize::MAX; n];
        vis[i] = 0;
        loop {
            let next = f[i] - 1;
            if vis[next] != usize::MAX {
                let d = vis[i] + 1 - vis[next];
                at_least = at_least.max(vis[next]);
                cycle_len = lcm(cycle_len, d);
                break;
            }
            vis[next] = vis[i] + 1;
            i = next;
        }
    }
    at_least.div_ceil(cycle_len).max(1) * cycle_len
}

fn lcm(a: usize, b: usize) -> usize {
    let g = gcd(a, b);
    a / g * b
}

fn gcd(mut a: usize, mut b: usize) -> usize {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}
