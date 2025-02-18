fn main() {
    input! { n: usize, k: usize }

    let j = n - k - 1;
    let mut r = vec![j / k; k];
    for i in 0..j % k {
        r[i] += 1;
    }
    println!("{}", r[0] + r[1] + 2);
    let mut cnt = 2;
    for i in 0..k {
        let mut pre = 1;
        for j in 0..=r[i] {
            println!("{} {}", pre, cnt);
            pre = cnt;
            cnt += 1;
        }
    }
}