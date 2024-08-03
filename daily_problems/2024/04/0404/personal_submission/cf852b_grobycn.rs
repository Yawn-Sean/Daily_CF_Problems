// core logic only
// submission: https://codeforces.com/problemset/submission/852/255489731
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, l: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut first = vec![Mod(0); m];
    scanner.iter(n).for_each(|i: usize| first[i % m] += Mod(1));

    let layer: Vec<usize> = scanner.iter(n).collect();
    let mut mat = vec![vec![Mod(0); m]; m];
    let mut cnt = vec![Mod(0); m];
    for &c in &layer {
        cnt[c % m] += Mod(1);
    }
    for (i, row) in mat.iter_mut().enumerate() {
        for (j, &c) in cnt.iter().enumerate() {
            row[(i + m - j) % m] += c;
        }
    }
    mat = mat_power(mat, l - 2);
    first = mat_mul_vec(mat, first);

    let mut ans = Mod(0);
    for (x, y) in scanner.iter::<usize>(n).zip(layer) {
        ans += first[(m - (x + y) % m) % m];
    }
    ans.0
}

fn mat_power(mut base: Vec<Vec<Mod>>, mut exp: usize) -> Vec<Vec<Mod>> {
    let n = base.len();
    let mut ret = vec![vec![Mod(0); n]; n];
    ret.iter_mut()
        .enumerate()
        .for_each(|(i, row)| row[i] = Mod(1));
    let mut tmp = vec![vec![Mod(0); n]; n];

    while exp > 0 {
        if exp & 1 != 0 {
            mat_mul(&mut tmp, &ret, &base);
            std::mem::swap(&mut tmp, &mut ret);
        }
        exp >>= 1;
        mat_mul(&mut tmp, &base, &base);
        std::mem::swap(&mut tmp, &mut base);
    }
    ret
}

fn mat_mul_vec(mat: Vec<Vec<Mod>>, v: Vec<Mod>) -> Vec<Mod> {
    mat.iter()
        .map(|row| {
            row.iter()
                .zip(&v)
                .fold(Mod(0), |acc, (&lhs, &rhs)| acc + lhs * rhs)
        })
        .collect()
}

fn mat_mul(ret: &mut [Vec<Mod>], lhs: &[Vec<Mod>], rhs: &[Vec<Mod>]) {
    for (row, lhs) in ret.iter_mut().zip(lhs) {
        for (c, sum) in row.iter_mut().enumerate() {
            *sum = Mod(0);
            for (&lhs, rhs) in lhs.iter().zip(rhs) {
                *sum += lhs * rhs[c];
            }
        }
    }
}

use std::ops::{Add, AddAssign, Mul, MulAssign};

#[derive(Clone, Copy)]
struct Mod<const M: usize = 1_000_000_007>(usize);

impl<const M: usize> Add for Mod<M> {
    type Output = Self;
    fn add(self, rhs: Self) -> Self {
        Mod((self.0 + rhs.0) % M)
    }
}

impl<const M: usize> AddAssign for Mod<M> {
    fn add_assign(&mut self, rhs: Self) {
        self.0 = (self.0 + rhs.0) % M;
    }
}

impl<const M: usize> Mul for Mod<M> {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        Mod((self.0 * rhs.0) % M)
    }
}

impl<const M: usize> MulAssign for Mod<M> {
    fn mul_assign(&mut self, rhs: Self) {
        self.0 = (self.0 * rhs.0) % M;
    }
}
