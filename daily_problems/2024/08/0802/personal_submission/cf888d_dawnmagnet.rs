fn comb(n: usize, k: usize) -> usize {
    let mut ans = 1;
    for i in 1..=k {
        ans *= n - i + 1;
        ans /= i;
    }
    ans
}

fn main() {
    input! { n: usize, k: usize }
    // println!("{:?} {:?}", v1, v2);
    let z = match k {
        1 => 1,
        2 => 1 + comb(n, 2),
        3 => 1 + comb(n, 2) + 2 * comb(n, 3),
        _ => 1 + comb(n, 2) + 2 * comb(n, 3) + 9 * comb(n, 4),
    };
    println!("{}", z);
}
