fn main() {
    input! { n: usize }
    let mut res = vec![0; 2 * n];
    for i in 0..((n + 1) / 2) {
        res[i] = i * 2 + 1;
        res[n - 1 - i] = i * 2 + 1;
    }
    for i in 0..(n / 2) {
        res[n + i] = i * 2 + 2;
        res[2 * n - 2 - i] = i * 2 + 2;
    }
    res[2 * n - 1] = n;
    for i in res {
        print!("{} ", i);
    }
}