fn main() {
    input! { t: i32 }
    for _ in 0..t {
        solve();
    }
}

fn solve() {
    input! { n: usize }
    input! { x: [u8; n * 2] }
    let mut ap = HashMap::new();
    let mut cur = 0;
    ap.insert(0, 0);
    for i in 0..n {
        cur += if x[i] == 1 { 1 } else { -1 };
        ap.insert(cur, i + 1);
    }
    // eprintln!("{:?}", ap);
    let mut ans = 2 * n - ap[&0];
    let mut cur = 0;
    for i in (n..2 * n).rev() {
        cur += if x[i] == 2 { 1 } else { -1 };
        if let Some(v) = ap.get(&cur) {
            ans = ans.min(i - v);
        }
    }
    println!("{}", ans);
}