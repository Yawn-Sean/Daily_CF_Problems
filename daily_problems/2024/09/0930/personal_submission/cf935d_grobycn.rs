//! core logic
//! submission: https://codeforces.com/contest/935/submission/283840516
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

#[derive(Clone, Copy)]
struct Mod(usize);

impl Mod {
    fn power(mut self, mut x: usize) -> Self {
        let mut ret = Mod(1);
        while x > 0 {
            if x & 1 != 0 {
                ret = ret * self;
            }
            self = self * self;
            x >>= 1;
        }
        ret
    }
    fn inv(self) -> Self {
        self.power(MOD - 2)
    }
}

impl std::ops::Add for Mod {
    type Output = Self;
    fn add(self, rhs: Self) -> Self {
        Mod((self.0 + rhs.0) % MOD)
    }
}

impl std::ops::Mul for Mod {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        Mod((self.0 * rhs.0) % MOD)
    }
}

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let s1: Vec<usize> = scanner.iter(n).collect();
    let s2: Vec<usize> = scanner.iter(n).collect();
    let invm = Mod(m).inv();
    let inv2m = Mod(2 * m).inv();
    let mut same_prob = Mod(1);
    let mut ans = Mod(0);

    for (&x, &y) in s1.iter().zip(&s2) {
        match (x, y) {
            (0, 0) => {
                let gt_prob = same_prob * Mod(m - 1) * inv2m;
                ans = ans + gt_prob;
                same_prob = same_prob * invm;
            }
            (0, _) => {
                let gt_prob = same_prob * Mod(m - y) * invm;
                ans = ans + gt_prob;
                same_prob = same_prob * invm;
            }
            (_, 0) => {
                let gt_prob = same_prob * Mod(x - 1) * invm;
                ans = ans + gt_prob;
                same_prob = same_prob * invm;
            }
            _ if x == y => {}
            _ if x < y => break,
            _ => {
                ans = ans + same_prob;
                break;
            }
        }
    }
    ans.0
}
