//! core logic only
//! submission: https://codeforces.com/problemset/submission/848/296374319
const MULTIPLE_TEST: bool = false;

fn solver(mut k: usize) -> impl Printable {
    if k == 0 {
        return String::from("a");
    }
    let mut ans = String::new();
    let mut c = b'a';
    while k > 0 {
        let mut len = 1;
        while (1 + len) * len / 2 <= k {
            len += 1;
        }
        k -= len * (len - 1) / 2;
        ans.extend(std::iter::repeat(c as char).take(len));
        c += 1;
    }
    ans
}
