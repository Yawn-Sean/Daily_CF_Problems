//! core logic only
//! submission: https://codeforces.com/problemset/submission/755/298427986
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, mut k: usize) -> impl Printable {
    k = k.min(n - k);
    let mut tr = Fenwick::new(n);
    let mut x = 0;
    let mut acc = 1;
    let ans = (0..n).map(move |_| {
        let y = (x + k) % n;
        acc += 1;
        // sum of range (x - k, x + k)
        acc += tr.query(x.saturating_sub(k - 1), (x + k).min(n));
        if x < k - 1 {
            let c = k - 1 - x;
            acc += tr.query(n - c, n);
        }
        if x + k > n {
            let c = x + k - n;
            acc += tr.query(0, c);
        }
        tr.inc(x, 1);
        x = y;
        acc
    });
    Sep::<_, ' '>(ans)
}

struct Fenwick {
    arr: Vec<usize>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    fn inc(&mut self, mut i: usize, d: usize) {
        while i < self.arr.len() {
            self.arr[i] += d;
            i += (i + 1) & !i;
        }
    }
    fn query_(&self, mut r: usize) -> usize {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
    fn query(&self, l: usize, r: usize) -> usize {
        self.query_(r) - self.query_(l)
    }
}
