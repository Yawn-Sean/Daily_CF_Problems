//! core logic only
//! submission: https://codeforces.com/problemset/submission/126/294783261
const MULTIPLE_TEST: bool = false;

fn solver(pic: Vec<String>) -> impl Printable {
    let mut ans = 0;
    let n = pic.len();
    let mut pic: Vec<_> = pic.into_iter().map(|r| r.into_bytes()).collect();

    let mut row = vec![0; n];
    let mut col = vec![0; n];
    for r in 0..n {
        for c in (r + 1..n).rev() {
            if row[r] ^ col[c] ^ pic[r][c] == b'1' {
                ans += 1;
                row[r] ^= 1;
                col[c] ^= 1;
                pic[r][r] ^= 1;
                pic[c][c] ^= 1;
            }
        }
    }
    row.iter_mut().for_each(|v| *v = 0);
    col.iter_mut().for_each(|v| *v = 0);
    for r in (0..n).rev() {
        for c in 0..r {
            if row[r] ^ col[c] ^ pic[r][c] == b'1' {
                ans += 1;
                row[r] ^= 1;
                col[c] ^= 1;
                pic[r][r] ^= 1;
                pic[c][c] ^= 1;
            }
        }
    }
    for i in 0..n {
        if pic[i][i] == b'1' {
            ans += 1;
        }
    }
    ans
}
