// core logic only
// submission: https://codeforces.com/contest/862/submission/263889396
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, x: usize) -> impl Printable {
    if n == 2 && x == 0 {
        return Err("NO");
    }
    let hibit = 1 << 18;
    let mut ans: Vec<_> = (0..n).collect();
    let xor = (0..n).fold(0, |acc, x| acc ^ x);
    ans[n - 1] ^= xor ^ x;
    if ans[n - 1] < n - 1 {
        if ans[n - 1] == 0 {
            ans[1] |= hibit;
        } else {
            ans[0] |= hibit;
        }
        ans[n - 1] |= hibit;
    }
    Ok("YES".cr().then(Sep::<_, ' '>(ans)))
}
