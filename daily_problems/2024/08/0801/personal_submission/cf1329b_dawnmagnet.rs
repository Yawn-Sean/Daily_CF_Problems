fn main() {
    input! { t: i32 }
    for _ in 0..t {
        solve();
    }
}

fn solve() {
    input! { mut a:i64, m: i64 }
    let mut v = vec![];
    let mut res = 0;
    for i in 0..32 {
        if a > (1 << i) {
            v.push(1 << i);
        } else {
            v.push(a);
            break;
        }
        a -= 1 << i;
    }
    for i in v {
        res = (res + 1) * (i + 1) - 1;
        res %= m;
    }
    println!("{res}");
}
