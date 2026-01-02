use std::io::prelude::*;

pub struct Scanner<R> {
    reader: R,
    buf_str: Vec<u8>,
    buf_iter: std::str::SplitAsciiWhitespace<'static>,
}

impl<R: BufRead> Scanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buf_str: Vec::new(),
            buf_iter: "".split_ascii_whitespace(),
        }
    }
    pub fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buf_iter.next() {
                return token.parse().ok().expect("Failed parse");
            }
            self.buf_str.clear();
            self.reader
                .read_until(b'\n', &mut self.buf_str)
                .expect("Failed read");
            self.buf_iter = unsafe {
                let slice = std::str::from_utf8_unchecked(&self.buf_str);
                std::mem::transmute(slice.split_ascii_whitespace())
            }
        }
    }
}

pub trait LazySegTreeOp {
    type S: Clone + Copy;
    type F: Clone + Copy;

    fn op(a: Self::S, b: Self::S) -> Self::S;
    fn e() -> Self::S;
    fn mapping(f: Self::F, x: Self::S) -> Self::S;
    fn composition(f: Self::F, g: Self::F) -> Self::F;
    fn id() -> Self::F;
}

pub struct LazySegTree<O: LazySegTreeOp> {
    n: usize,
    size: usize,
    log: u32,
    d: Vec<O::S>,
    lz: Vec<O::F>,
}

impl<O: LazySegTreeOp> LazySegTree<O> {
    pub fn new(n: usize) -> Self {
        Self::from_vec(&vec![O::e(); n])
    }

    pub fn from_vec(v: &Vec<O::S>) -> Self {
        let n = v.len();
        let size = n.next_power_of_two();
        let log = size.trailing_zeros();
        let mut d = vec![O::e(); 2 * size];
        let lz = vec![O::id(); size];

        for i in 0..n {
            d[size + i] = v[i];
        }

        let mut seg = Self {
            n,
            size,
            log,
            d,
            lz,
        };

        for i in (1..size).rev() {
            seg.push_up(i);
        }

        seg
    }

    pub fn set(&mut self, mut p: usize, x: O::S) {
        assert!(p < self.n);
        p += self.size;
        for i in (1..=self.log).rev() {
            self.push_down(p >> i);
        }
        self.d[p] = x;
        for i in 1..=self.log {
            self.push_up(p >> i);
        }
    }

    pub fn get(&mut self, mut p: usize) -> O::S {
        assert!(p < self.n);
        p += self.size;
        for i in (1..=self.log).rev() {
            self.push_down(p >> i);
        }
        self.d[p]
    }

    pub fn prod(&mut self, mut l: usize, mut r: usize) -> O::S {
        assert!(l <= r && r <= self.n);
        if l == r {
            return O::e();
        }

        l += self.size;
        r += self.size;

        for i in (1..=self.log).rev() {
            if ((l >> i) << i) != l {
                self.push_down(l >> i);
            }
            if ((r >> i) << i) != r {
                self.push_down((r - 1) >> i);
            }
        }

        let mut ansl = O::e();
        let mut ansr = O::e();

        while l < r {
            if l & 1 == 1 {
                ansl = O::op(ansl, self.d[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                ansr = O::op(self.d[r], ansr);
            }
            l >>= 1;
            r >>= 1;
        }

        O::op(ansl, ansr)
    }

    pub fn all_prod(&self) -> O::S {
        self.d[1]
    }

    pub fn apply_at(&mut self, mut p: usize, f: O::F) {
        assert!(p < self.n);
        p += self.size;
        for i in (1..=self.log).rev() {
            self.push_down(p >> i);
        }
        self.d[p] = O::mapping(f, self.d[p]);
        for i in 1..=self.log {
            self.push_up(p >> i);
        }
    }

    pub fn apply(&mut self, mut l: usize, mut r: usize, f: O::F) {
        assert!(l <= r && r <= self.n);
        if l == r {
            return;
        }

        l += self.size;
        r += self.size;

        for i in (1..=self.log).rev() {
            if ((l >> i) << i) != l {
                self.push_down(l >> i);
            }
            if ((r >> i) << i) != r {
                self.push_down((r - 1) >> i);
            }
        }

        let mut x = l;
        let mut y = r;
        while x < y {
            if x & 1 == 1 {
                self.all_apply(x, f);
                x += 1;
            }
            if y & 1 == 1 {
                y -= 1;
                self.all_apply(y, f);
            }
            x >>= 1;
            y >>= 1;
        }

        for i in 1..=self.log {
            if ((l >> i) << i) != l {
                self.push_up(l >> i);
            }
            if ((r >> i) << i) != r {
                self.push_up((r - 1) >> i);
            }
        }
    }

    fn all_apply(&mut self, k: usize, f: O::F) {
        self.d[k] = O::mapping(f, self.d[k]);
        if k < self.size {
            self.lz[k] = O::composition(f, self.lz[k]);
        }
    }

    fn push_up(&mut self, k: usize) {
        self.d[k] = O::op(self.d[2 * k], self.d[2 * k + 1]);
    }

    fn push_down(&mut self, k: usize) {
        self.all_apply(2 * k, self.lz[k]);
        self.all_apply(2 * k + 1, self.lz[k]);
        self.lz[k] = O::id();
    }
}

struct M;

impl LazySegTreeOp for M {
    type S = i32;
    type F = i32;

    fn op(a: Self::S, b: Self::S) -> Self::S {
        a.max(b)
    }

    fn e() -> Self::S {
        0
    }

    fn mapping(f: Self::F, s: Self::S) -> Self::S {
        f + s
    }

    fn composition(f: Self::F, g: Self::F) -> Self::F {
        f + g
    }

    fn id() -> Self::F {
        0
    }
}

type T = LazySegTree<M>;

fn solve(scanner: &mut Scanner<std::io::StdinLock<'static>>) {
    let n: usize = scanner.next();
    let mut a = vec![0; n];
    let mut first = vec![-1; n + 1];
    let mut last = vec![-1; n + 1];
    let mut prev = vec![-1; n + 1];
    let mut t = T::new(n);
    for i in 0..n {
        a[i] = scanner.next();
        let x = a[i];
        if first[x] == -1 {
            first[x] = i as i32;
            last[x] = i as i32;
            t.apply(0, n, 1);
        } else {
            last[x] = i as i32;
        }
    }
    let mut ans = 0;
    for i in 0..n {
        let x = a[i];
        if i as i32 == last[x] {
            t.apply(0, n, -1);
            t.apply(first[x] as usize + 1, n, 1);
        }
        t.apply(prev[x] as usize + 1, i + 1, 1);
        prev[x] = i as i32;
        ans = ans.max(t.prod(0, i + 1));
    }
    println!("{}", ans);
}

fn main() {
    let mut scanner = Scanner::new(std::io::stdin().lock());
    let t: usize = scanner.next();
    for _ in 0..t {
        solve(&mut scanner);
    }
}
