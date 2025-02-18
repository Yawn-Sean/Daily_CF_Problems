//! core logic only
//! submission: https://codeforces.com/problemset/submission/340/281731893
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

#[derive(Clone, Copy)]
struct Mod(usize);
impl Mod {
    fn power(mut self, mut x: usize) -> Self {
        let mut ret = Mod(1);
        while x > 0 {
            if x & 1 != 0 {
                ret *= self;
            }
            x >>= 1;
            self *= self;
        }
        ret
    }
}
impl std::ops::AddAssign for Mod {
    fn add_assign(&mut self, rhs: Self) {
        self.0 = (self.0 + rhs.0) % MOD;
    }
}
impl std::ops::SubAssign for Mod {
    fn sub_assign(&mut self, rhs: Self) {
        self.0 = (self.0 + MOD - rhs.0) % MOD;
    }
}
impl std::ops::Mul for Mod {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        Mod((self.0 * rhs.0) % MOD)
    }
}
impl std::ops::MulAssign for Mod {
    fn mul_assign(&mut self, rhs: Self) {
        self.0 = (self.0 * rhs.0) % MOD;
    }
}

fn solver(perm: Vec<i32>) -> impl Printable {
    let n = perm.len();
    let mut undetermined = 0;
    let mut seen = vec![false; n];
    for &x in &perm {
        if x == -1 {
            undetermined += 1;
        } else {
            seen[x as usize - 1] = true;
        }
    }
    let maybe_fixed = perm.into_iter()
        .zip(seen)
        .filter(|&(x, seen)| x == -1 && !seen)
        .count();

    let mut fac = vec![Mod(0); n + 1];
    fac[0] = Mod(1);
    for i in 1..=n {
        fac[i] = fac[i - 1] * Mod(i);
    }
    let mut fac_inv = vec![Mod(0); n + 1];
    fac_inv[n] = fac[n].power(MOD - 2);
    for i in (1..=n).rev() {
        fac_inv[i - 1] = fac_inv[i] * Mod(i);
    }
    let comb = |n: usize, k: usize| fac[n] * fac_inv[k] * fac_inv[n - k];
    
    let mut ans = Mod(0);
    for fixed in 0..=maybe_fixed {
        let free = undetermined - fixed;
        if fixed & 1 == 0 {
            ans += comb(maybe_fixed, fixed) * fac[free];
        } else {
            ans -= comb(maybe_fixed, fixed) * fac[free];
        }
    }
    ans.0
}
