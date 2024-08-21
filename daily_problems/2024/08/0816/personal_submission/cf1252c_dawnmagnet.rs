fn main() {
    input! { n: usize, q: usize, a: [usize; n], b: [usize; n] }
    input! { query: [(usize, usize, usize, usize); q] }
    let mut at = vec![0; n];
    let mut bt = vec![0; n];
    for i in 1..n {
        at[i] = at[i - 1] + (a[i] + a[i - 1]) % 2;
        bt[i] = bt[i - 1] + (b[i] + b[i - 1]) % 2;
    }
    for (x1, y1, x2, y2) in query {
        if at[x1 - 1] == at[x2 - 1] && bt[y1 - 1] == bt[y2 - 1] {
            println!("YES");
        } else {
            println!("NO");
        }
    }
}