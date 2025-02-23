//! core logic only
//! submission: https://codeforces.com/problemset/submission/364/293837163
const MULTIPLE_TEST: bool = false;

fn solver(a: u32, s: String) -> impl Printable {
    let n = s.len();
    let mut presum = vec![0; n + 1];
    for (i, b) in s.bytes().enumerate() {
        presum[i + 1] = presum[i] + (b - b'0') as u32;
    }
    // sum of s[l..r]
    let sum = |l: usize, r: usize| presum[r] - presum[l];
    let mut count = std::collections::HashMap::new();
    for y in 0..n {
        for x in 0..=y {
            let sumi = sum(x, y + 1);
            *count.entry(sumi).or_insert(0usize) += 1;
        }
    }

    if a == 0 {
        let cnt0 = *count.get(&0).unwrap_or(&0);
        let total = n * (n + 1) / 2;
        return total * total - (total - cnt0) * (total - cnt0);
    }
    let mut ans = 0;
    for (&si, &cnt) in count.iter() {
        if si == 0 || a % si != 0 {
            continue;
        }
        let sj = a / si;
        ans += cnt * *count.get(&sj).unwrap_or(&0);
    }
    ans
}
