// core logic only
// submission: https://codeforces.com/problemset/submission/1200/257869751
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    fn transpose<T: Copy>(mat: &mut [Vec<T>]) {
        let n = mat.len();
        for r in 0..n {
            for c in 0..r {
                let tmp = mat[r][c];
                mat[r][c] = mat[c][r];
                mat[c][r] = tmp;
            }
        }
    }
    fn count(mat: &[Vec<u8>], diff: &mut [Vec<i64>], k: usize) {
        let n = mat.len();
        let m = diff.len();
        for (r, row) in mat.iter().enumerate() {
            let tot_bcnt = row.iter().filter(|&x| *x == b'B').count();
            if tot_bcnt == 0 {
                diff[0][0] += 1;
                diff[0][m - 1] -= 1;
                diff[m - 1][0] -= 1;
                diff[m - 1][m - 1] += 1;
            } else {
                let mut bcnt = usize::MAX;
                let minr = r.saturating_sub(k - 1);
                let maxr = (r + 1).min(m - 1);
                let mut prev = 0;
                for (c, w) in row.windows(k).enumerate() {
                    if bcnt == usize::MAX {
                        bcnt = w.iter().filter(|&x| *x == b'B').count();
                    } else {
                        bcnt += usize::from(w[k - 1] == b'B');
                        bcnt -= usize::from(prev == b'B');
                    }
                    prev = w[0];
                    if bcnt == tot_bcnt {
                        diff[minr][c] += 1;
                        diff[minr][c + 1] -= 1;
                        diff[maxr][c] -= 1;
                        diff[maxr][c + 1] += 1;
                    }
                }
            }
        }
    }

    let mut mat: Vec<_> = scanner.iter(n).map(|s: String| s.into_bytes()).collect();
    let m = n - k + 1;
    let mut diff = vec![vec![0i64; m + 1]; m + 1];
    count(&mat, &mut diff, k);
    transpose(&mut mat);
    transpose(&mut diff);
    count(&mat, &mut diff, k);

    for r in 0..m {
        for c in 1..m {
            diff[r][c] += diff[r][c - 1];
        }
    }
    for c in 0..m {
        for r in 1..m {
            diff[r][c] += diff[r - 1][c];
        }
    }
    *diff.iter().map(|row| row.iter()).flatten().max().unwrap()
}
