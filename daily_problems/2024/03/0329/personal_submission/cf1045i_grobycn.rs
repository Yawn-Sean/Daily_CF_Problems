// core logic only
// submission: https://codeforces.com/problemset/submission/1045/253944709
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut count = std::collections::HashMap::new();
    let mut ans = 0usize;
    for s in scanner.iter::<String>(n) {
        let m = s.bytes().fold(0, |acc, b| acc ^ (1 << (b - b'a')));
        if let Some(&c) = count.get(&m) {
            ans += c;
        }
        for i in 0..26 {
            if let Some(&c) = count.get(&(m ^ (1 << i))) {
                ans += c;
            }
        }
        *count.entry(m).or_insert(0) += 1;
    }
    ans
}
