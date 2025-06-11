//! core logic only
//! submission: https://codeforces.com/problemset/submission/990/283989915
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, a: usize, b: usize) -> impl Printable {
    if a != 1 && b != 1 {
        return Err("NO");
    }
    if a == 1 && b == 1 && (n == 2 || n == 3) {
        return Err("NO");
    }
    let mut mat = vec![vec![b'0'; n]; n];
    let side = if a != 1 { n - a } else { n - b };
    for i in 1..=side {
        mat[i - 1][i] = b'1';
        mat[i][i - 1] = b'1';
    }
    if a == 1 {
        for i in 0..n {
            for j in i + 1..n {
                mat[i][j] ^= 1;
                mat[j][i] ^= 1;
            }
        }
    }
    let mat = mat
        .into_iter()
        .map(|row| unsafe { String::from_utf8_unchecked(row) });
    Ok("YES".cr().then(Sep::<_, '\n'>(mat)))
}
