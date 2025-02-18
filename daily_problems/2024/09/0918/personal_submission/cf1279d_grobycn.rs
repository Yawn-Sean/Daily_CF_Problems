//! core logic only
//! submission: https://codeforces.com/problemset/submission/1279/281734389
const MULTIPLE_TEST: bool = false;
const MOD: usize = 998_244_353;

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
impl std::ops::Div for Mod {
    type Output = Self;
    fn div(self, rhs: Self) -> Self {
        self * rhs.power(MOD - 2)
    }
}
impl std::ops::DivAssign for Mod {
    fn div_assign(&mut self, rhs: Self) {
        *self = *self / rhs
    }
}

fn solver(lists: Vec<Vec<usize>>) -> impl Printable {
    let n = lists.len();
    // sum_{i, j} 1/n * 1/k_i * x_j/n
    let mut count = std::collections::HashMap::new();
    for list in &lists {
        for &x in list {
            *count.entry(x).or_insert(0) += 1;
        }
    }

    let mut ans = Mod(0);
    for list in &lists {
        let prob_den = Mod(list.len());
        let mut prob_num = Mod(0);
        for x in list {
            let c = count[x];
            prob_num += Mod(c);
        }
        ans += prob_num / prob_den;
    }
    ans /= Mod(n) * Mod(n);
    ans.0
}
