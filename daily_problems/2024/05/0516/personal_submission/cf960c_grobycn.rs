// core logic only
// submission: https://codeforces.com/problemset/submission/960/261207194
const MULTIPLE_TEST: bool = false;

fn solver(mut x: usize, d: usize) -> impl Printable {
    let mut ans = vec![];
    let mut a = 1;
    for cnt in (1..=32).rev() {
        let seq_cnt = (1 << cnt) - 1;
        while x >= seq_cnt {
            ans.extend(std::iter::repeat(a).take(cnt));
            x -= seq_cnt;
            a += d;
        }
    }
    ans.len().cr().then(Sep::<_, ' '>(ans))
}
