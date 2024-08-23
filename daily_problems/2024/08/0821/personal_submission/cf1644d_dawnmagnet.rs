fn main() {
    input! { t: i32 }
    for _ in 0..t {
        solve();
    }
}

fn solve() {
    input! { n: usize, m: usize, k: usize, q: usize }
    input! { qs: [(usize, usize); q] }
    let mut x = vec![false; n];
    let mut cx = 0;
    let mut y = vec![false; m];
    let mut cy = 0;
    let mut res = 1;
    for i in (0..q).rev() {
        let mut ct = 0;
        if !x[qs[i].0 - 1] {
            x[qs[i].0 - 1] = true;
            cx += 1;
            if cy != m {
                ct += 1;
            }
        }
        if !y[qs[i].1 - 1] {
            y[qs[i].1 - 1] = true;
            cy += 1;
            if cx != n {
                ct += 1;
            }
        }
        if ct > 0 {
            res *= k;
            res %= 998244353;
        }
    }
    println!("{}", res);
}