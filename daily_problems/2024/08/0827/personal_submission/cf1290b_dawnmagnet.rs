fn main() {
    input! { a: String }
    let n = a.len();
    let a = a.as_bytes();
    let mut cnt = vec![vec![0; n + 1]; 26];
    for (i, c) in a.iter().enumerate() {
        for j in 0..26 {
            cnt[j][i + 1] = cnt[j][i];
        }
        cnt[(c - b'a') as usize][i + 1] += 1;
    }
    let mut ans = 0;
    input! { q: usize }
    for _ in 0..q {
        input! { l: usize, r: usize }
        let mut c = 0;
        for j in 0..26 {
            if cnt[j][r] - cnt[j][l - 1] > 0 {
                c += 1;
            }
        }
        if r != l && c <= 2 && a[l - 1] == a[r - 1] {
            println!("No");
        } else {
            println!("Yes");
        }
    }
}