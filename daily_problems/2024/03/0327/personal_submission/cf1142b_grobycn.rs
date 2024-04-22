// core logic only
// submission: https://codeforces.com/problemset/submission/1142/253501464
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let perm: Vec<_> = scanner.iter(n).map(|x: usize| x - 1).collect();
    let mut prev = vec![0; n];
    for w in perm.windows(2) {
        prev[w[1]] = w[0];
    }
    prev[perm[0]] = perm[n - 1];

    let mut last = vec![m; n];
    let mut lift = vec![[m; 18]; m + 1];
    let mut leftmost = vec![0; m + 1];
    let dist = n - 1;
    for (i, x) in scanner.iter::<usize>(m).enumerate() {
        let x = x - 1;
        lift[i][0] = last[prev[x]];
        for k in 1..18 {
            lift[i][k] = lift[lift[i][k - 1]][k - 1];
        }
        let mut cur = i;
        for k in 0..18 {
            if dist & (1 << k) != 0 {
                cur = lift[cur][k];
            }
        }
        leftmost[i + 1] = leftmost[i].max((cur + 1) % (m + 1));
        last[x] = i;
    }

    let ans = scanner
        .iter(q)
        .map(|(l, r): (usize, usize)| {
            if r + 1 - l < n {
                return b'0';
            }
            if leftmost[r] >= l {
                b'1'
            } else {
                b'0'
            }
        })
        .collect();

    unsafe { String::from_utf8_unchecked(ans) }
}
