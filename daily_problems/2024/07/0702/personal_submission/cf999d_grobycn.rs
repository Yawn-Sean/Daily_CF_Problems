// core logic only
// submission: https://codeforces.com/problemset/submission/999/268477703
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut count = vec![0; m];
    let mut indices = vec![vec![]; m];
    let mut ans = Vec::with_capacity(n);
    for (i, x) in scanner.iter::<usize>(n).enumerate() {
        ans.push(x);
        indices[x % m].push(i);
    }
    let mut stk = vec![];
    let k = n / m;
    let mut op = 0;
    for i in 0..2 * m {
        let i = i % m;
        while !stk.is_empty() && indices[i].len() < k {
            let j = stk.pop().unwrap();
            let d = (i + m - ans[j] % m) % m;
            ans[j] += d;
            op += d;
            indices[i].push(j);
        }
        while indices[i].len() > k {
            stk.push(indices[i].pop().unwrap());
        }
    }

    op.cr().then(Sep::<_, ' '>(ans))
}
