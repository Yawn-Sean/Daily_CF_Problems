//! core logic only
//! submission: https://codeforces.com/problemset/submission/405/286861748
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut sum = (0..n)
        .filter_map(|i| scanner.iter::<u8>(n).nth(i))
        .fold(0, |acc, x| acc ^ x);
    let mut ans = vec![];
    let q = usize::from_scanner(scanner);
    for _ in 0..q {
        let ty = u8::from_scanner(scanner);
        if ty == 3 {
            ans.push(sum + b'0');
        } else {
            let _ = usize::from_scanner(scanner);
            sum ^= 1;
        }
    }
    unsafe { String::from_utf8_unchecked(ans) }
}
