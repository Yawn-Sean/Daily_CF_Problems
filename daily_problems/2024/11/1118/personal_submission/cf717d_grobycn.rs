//! core logic only
//! submission: https://codeforces.com/contest/717/submission/292192239
const MULTIPLE_TEST: bool = false;

fn solver(mut n: usize, x: usize, scanner: &mut Scanner) -> impl Printable {
    let p: Vec<f64> = scanner.iter(x + 1).collect();
    let m = (x + 1).next_power_of_two();
    let mut mat = vec![vec![0.0; m]; m];
    for old in 0..m {
        for (x, &p) in p.iter().enumerate() {
            let new = old ^ x;
            mat[new][old] += p;
        }
    }

    let mut pow = vec![vec![0.0; m]; m];
    pow.iter_mut().enumerate().for_each(|(i, row)| row[i] = 1.0);
    let mut buf = vec![vec![0.0; m]; m];
    let mat_mul = |ret: &mut [Vec<f64>], lhs: &[Vec<f64>], rhs: &[Vec<f64>]| {
        for r in 0..m {
            for c in 0..m {
                let mut sum = 0.0;
                for i in 0..m {
                    sum += lhs[r][i] * rhs[i][c];
                }
                ret[r][c] = sum;
            }
        }
    };

    while n > 0 {
        if n & 1 != 0 {
            mat_mul(&mut buf, &pow, &mat);
            std::mem::swap(&mut buf, &mut pow);
        }
        n >>= 1;
        mat_mul(&mut buf, &mat, &mat);
        std::mem::swap(&mut buf, &mut mat);
    }

    1.0 - pow[0][0]
}
