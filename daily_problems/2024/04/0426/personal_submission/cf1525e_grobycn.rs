// core logic only
// submission: https://codeforces.com/contest/1525/submission/259008784
const MULTIPLE_TEST: bool = false;

fn solver(Mat(d): Mat<usize>) -> impl Printable {
    let (n, m) = (d.len(), d[0].len());

    let mut fac: Vec<Mod> = vec![Mod(0); n + 1];
    fac[0] = Mod(1);
    for i in 1..=n {
        fac[i] = fac[i - 1] * Mod(i);
    }

    let mut facinv = vec![Mod(0); n + 1];
    facinv[n] = fac[n].inv();
    for i in (1..=n).rev() {
        facinv[i - 1] = facinv[i] * Mod(i);
    }

    let mut ans = Mod(0);
    for j in 0..m {
        let mut count = vec![0; n + 1];
        for i in 0..n {
            count[n + 1 - d[i][j]] += 1;
        }
        let mut e = Mod(1);
        let mut sum = 0;
        for (slot, &c) in count.iter().rev().enumerate() {
            if c == 0 {
                continue;
            }
            sum += c;
            if sum > slot {
                e = Mod(0);
                break;
            }
            e *= fac[slot - sum + c] * facinv[slot - sum];
        }
        e *= facinv[n];
        ans += Mod(1) - e;
    }
    ans.0
}

#[derive(Clone, Copy)]
struct Mod<const M: usize = 998244353>(usize);

impl<const M: usize> Mod<M> {
    fn power(self, mut x: usize) -> Self {
        let mut ret = Mod(1);
        let mut base = self;
        while x > 0 {
            if x & 1 != 0 {
                ret *= base;
            }
            base *= base;
            x >>= 1;
        }
        ret
    }
    fn inv(self) -> Self {
        self.power(M - 2)
    }
}

use std::ops::{Add, AddAssign, Mul, MulAssign, Sub};

impl<const M: usize> Add for Mod<M> {
    type Output = Self;
    fn add(self, rhs: Self) -> Self::Output {
        Mod((self.0 + rhs.0) % M)
    }
}

impl<const M: usize> AddAssign for Mod<M> {
    fn add_assign(&mut self, rhs: Self) {
        self.0 = (self.0 + rhs.0) % M;
    }
}

impl<const M: usize> Sub for Mod<M> {
    type Output = Self;
    fn sub(self, rhs: Self) -> Self::Output {
        Mod((self.0 + M - rhs.0) % M)
    }
}

impl<const M: usize> Mul for Mod<M> {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self::Output {
        Mod((self.0 * rhs.0) % M)
    }
}

impl<const M: usize> MulAssign for Mod<M> {
    fn mul_assign(&mut self, rhs: Self) {
        self.0 = (self.0 * rhs.0) % M;
    }
}
