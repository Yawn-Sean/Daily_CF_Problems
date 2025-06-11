fn main() {
    input! { n: usize }
    input! { mut v: [i32; n] }
    let mut l = 0;
    while l + 1 < n && v[l + 1] > v[l] {
        l += 1;
    }
    let mut r = n - 1;
    while r > 0 && v[r - 1] > v[r] {
        r -= 1;
    }
    if (((l + 1) | (n - r)) & 1) == 0 {
        println!("Bob");
    } else {
        println!("Alice");
    }
}