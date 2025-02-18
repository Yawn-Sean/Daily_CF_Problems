fn main() {
    input! { n: usize }
    if n % 4 != 0 {
        println!("! -1");
        return;
    }
    let a = query(0, n);
    if a == 0 {
        println!("! 1");
        return;
    }
    // g(a) = a
    // g(a + n / 2) = -a
    // binary search
    let mut l = 0;
    let mut r = n / 2;
    while l <= r {
        let m = (l + r) / 2;
        let b = query(m, n);
        // println!("DEBUG        {} {}", m, b);
        // println!("DEBUG        {} {}", l, r);
        if b == 0 {
            println!("! {}", m + 1);
            return;
        }
        if b * a > 0 {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    println!("! -1");
}