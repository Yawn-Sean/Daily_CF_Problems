// core logic only
// submission: https://codeforces.com/problemset/submission/1095/262384535
const MULTIPLE_TEST: bool = false;

fn solver(remembered: Vec<(usize, usize)>) -> impl Printable {
    let n = remembered.len();
    if n == 3 {
        return Sep::<_, ' '>(vec![1, 2, 3]);
    }
    let mut ans = Vec::with_capacity(n);
    ans.push(1);
    let mut cur = 1;
    for _ in 1..n {
        let (a1, a2) = remembered[cur - 1];
        let (b1, b2) = remembered[a1 - 1];
        if b1 == a2 || b2 == a2 {
            ans.push(a1);
            cur = a1;
        } else {
            ans.push(a2);
            cur = a2;
        }
    }
    Sep::<_, ' '>(ans)
}
