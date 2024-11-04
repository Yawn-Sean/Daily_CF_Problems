//! core logic only
//! submission: https://codeforces.com/problemset/submission/1648/282648285
const MULTIPLE_TEST: bool = false;
const MOD: i64 = 998_244_353;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut fac = vec![Mod(1); n + 1];
    for i in 1..=n {
        fac[i] = fac[i - 1] * Mod(i as i64);
    }
    let mut invfac = vec![Mod(0); n + 1];
    invfac[n] = fac[n].power(MOD as usize - 2);
    for i in (1..=n).rev() {
        invfac[i - 1] = invfac[i] * Mod(i as i64);
    }

    let mut arr = vec![0; 200_001];
    for x in scanner.iter::<usize>(n) {
        arr[x] += 1;
    }
    let mut den = Mod(1);
    for &c in &arr {
        den = den * invfac[c as usize];
    }
    let mut tr = Fenwick::from(arr);

    let mut ans = Mod(0);
    for (x, num) in scanner.iter::<usize>(m).zip((0..n).rev()) {
        let cnt = tr._query(x);
        ans = ans + Mod(cnt) * fac[num] * den;
        let xcnt = tr.query(x, x + 1) as usize;
        if xcnt == 0 {
            return ans.0;
        }
        tr.inc(x, -1);
        den = den * fac[xcnt] * invfac[xcnt - 1];
    }

    if n < m {
        ans = ans + Mod(1);
    }
    ans.0
}

struct Fenwick {
    arr: Vec<i64>
}

impl From<Vec<i64>> for Fenwick {
    fn from(mut arr: Vec<i64>) -> Self {
        let n = arr.len();
        for i in 0..n {
            let p = i + ((i + 1) & !i);
            if p < n {
                arr[p] += arr[i];
            }
        }
        Self { arr }
    }
}

impl Fenwick {
    pub fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    fn _query(&self, mut r: usize) -> i64 {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
    pub fn query(&self, l: usize, r: usize) -> i64 {
        self._query(r) - self._query(l)
    }
    pub fn inc(&mut self, mut i: usize, d: i64) {
        while i < self.arr.len() {
            self.arr[i] += d;
            i += (i + 1) & !i;
        }
    }
}

#[derive(Clone, Copy)]
struct Mod(i64);

impl Mod {
    fn power(mut self, mut x: usize) -> Self {
        let mut ret = Mod(1);
        while x != 0 {
            if x & 1 != 0 {
                ret = ret * self;
            }
            x >>= 1;
            self = self * self;
        }
        ret
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
