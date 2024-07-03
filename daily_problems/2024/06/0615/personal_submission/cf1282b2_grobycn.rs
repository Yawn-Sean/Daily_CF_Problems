// core logic only
// submission: https://codeforces.com/contest/1282/submission/265827793
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, p: i32, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut a: Vec<i32> = scanner.iter(n).collect();
    a.sort_unstable();
    let mut presum = 0;
    let mut ans = 0;
    for (s, &x) in a[..k].iter().enumerate() {
        presum += x;
        let mut cnt = s + 1;
        let mut sum = if cnt == k { x } else { presum };
        if sum <= p {
            ans = ans.max(cnt);
        } else {
            continue;
        }
        for i in (s..n).step_by(k).skip(1) {
            cnt += k;
            sum += a[i];
            if sum <= p {
                ans = ans.max(cnt);
            } else {
                break;
            }
        }
    }
    ans
}
