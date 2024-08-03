// core logic only
// submission: https://codeforces.com/problemset/submission/623/256921876
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut conn = vec![vec![false; n]; n];
    for (mut u, mut v) in scanner.iter::<(usize, usize)>(m) {
        (u, v) = (u - 1, v - 1);
        conn[u][v] = true;
        conn[v][u] = true;
    }

    let mut ans = vec![0; n];
    for (i, b) in ans.iter_mut().enumerate() {
        if conn[i].iter().filter(|&c| *c).count() == n - 1 {
            *b = b'b';
        }
    }
    for i in 0..n {
        if ans[i] == b'b' {
            continue;
        }
        if ans[i] == 0 {
            ans[i] = b'a';
        }
        let a = ans[i];
        let c = if a == b'a' { b'c' } else { b'a' };
        for j in (0..n).filter(|&j| j != i) {
            if ans[j] == b'b' {
                continue;
            }
            if ans[j] == 0 {
                ans[j] = if conn[i][j] { a } else { c };
            }
            if conn[i][j] ^ (ans[i] == ans[j]) {
                return Err("No");
            }
        }
    }

    let ans = unsafe { String::from_utf8_unchecked(ans) };
    Ok("Yes".cr().then(ans))
}
