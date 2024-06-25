// core logic only
// submission: https://codeforces.com/contest/551/submission/264604961
const MULTIPLE_TEST: bool = false;

fn mat_mul(lhs: [[usize; 2]; 2], rhs: [[usize; 2]; 2], m: usize) -> [[usize; 2]; 2] {
    [
        [
            (lhs[0][0] * rhs[0][0] + lhs[0][1] * rhs[1][0]) % m,
            (lhs[0][0] * rhs[0][1] + lhs[0][1] * rhs[1][1]) % m,
        ],
        [
            (lhs[1][0] * rhs[0][0] + lhs[1][1] * rhs[1][0]) % m,
            (lhs[1][0] * rhs[0][1] + lhs[1][1] * rhs[1][1]) % m,
        ],
    ]
}

fn solver(mut n: usize, k: usize, l: usize, m: usize) -> impl Printable {
    if (l < 64 && k >> l != 0) || m == 1 {
        return 0;
    }

    let mut tot = 1;
    let mut pow2 = 2;
    let mut mat = [[1, 0], [0, 1]];
    let mut mat_pow2 = [[1, 1], [1, 0]];
    while n > 0 {
        if n & 1 != 0 {
            tot = (tot * pow2) % m;
            mat = mat_mul(mat, mat_pow2, m);
        }
        pow2 = (pow2 * pow2) % m;
        mat_pow2 = mat_mul(mat_pow2, mat_pow2, m);
        n >>= 1;
    }
    let cnt0 = (mat[0][0] + mat[1][0]) % m;
    let cnt1 = (tot + m - cnt0) % m;
    let count = [cnt0, cnt1];
    (0..l)
        .map(|i| count[(k >> i) & 1])
        .fold(1, |acc, x| (acc * x) % m)
}



