// core logic only
// submission: https://codeforces.com/problemset/submission/33/266781667
const MULTIPLE_TEST: bool = false;

fn solver(s: String, t: String, n: usize, scanner: &mut Scanner) -> impl Printable {
    if s.len() != t.len() {
        return Err(-1);
    }
    let mut cost = [[usize::MAX / 2; 26]; 26];
    (0..26).for_each(|i| cost[i][i] = 0);
    for (a, b, w) in scanner.iter::<(char, char, usize)>(n) {
        let (a, b) = ((a as u8 - b'a') as usize, (b as u8 - b'a') as usize);
        cost[a][b] = cost[a][b].min(w);
    }

    for k in 0..26 {
        for i in 0..26 {
            for j in 0..26 {
                cost[i][j] = cost[i][j].min(cost[i][k] + cost[k][j]);
            }
        }
    }

    let mut ans = Vec::with_capacity(s.len());
    let mut sum = 0;
    for (a, b) in s.bytes().zip(t.bytes()) {
        if a == b {
            ans.push(a);
            continue;
        }
        let (a, b) = ((a as u8 - b'a') as usize, (b as u8 - b'a') as usize);
        let (mut mn, mut mnat) = (usize::MAX / 2, 0);
        for c in 0..26 {
            let x = cost[a][c] + cost[b][c];
            if x < mn {
                mnat = c;
                mn = x;
            }
        }
        if mn >= usize::MAX / 2 {
            return Err(-1);
        }
        ans.push(mnat as u8 + b'a');
        sum += mn;
    }

    let ans = unsafe { String::from_utf8_unchecked(ans) };
    Ok(sum.cr().then(ans))
}
