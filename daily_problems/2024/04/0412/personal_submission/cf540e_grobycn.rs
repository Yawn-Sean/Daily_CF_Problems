// core logic only
// submission: https://codeforces.com/problemset/submission/540/256233826
const MULTIPLE_TEST: bool = false;

fn solver(swaps: Vec<(usize, usize)>) -> impl Printable {
    let mut seq = std::collections::HashMap::new();
    for (x, y) in swaps {
        let xv = *seq.get(&x).unwrap_or(&x);
        let yv = *seq.get(&y).unwrap_or(&y);
        seq.insert(x, yv);
        seq.insert(y, xv);
    }
    let mut ks: Vec<_> = seq.keys().copied().collect();
    ks.sort_unstable();
    let n = ks.len() * 2;
    let mut tr = Fenwick::new(n);
    let mut ans = 0;
    for (i, &k) in ks.iter().enumerate() {
        if i > 0 {
            let cnt = k - ks[i - 1] - 1;
            if cnt > 0 {
                let idx = 2 * i - 1;
                ans += tr.query(idx + 1, n) * cnt;
                tr.inc(idx, cnt);
            }
        }
        let v = seq[&k];
        let idx = 2 * ks.binary_search(&v).unwrap();
        ans += tr.query(idx + 1, n);
        tr.inc(idx, 1);
    }
    ans
}

struct Fenwick {
    arr: Vec<usize>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    fn inc(&mut self, mut i: usize, d: usize) {
        i += 1;
        while i <= self.arr.len() {
            self.arr[i - 1] += d;
            i += i & !(i - 1);
        }
    }
    // query sum of 0..r
    fn _query(&self, mut r: usize) -> usize {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
    // query sum of l..r
    fn query(&self, l: usize, r: usize) -> usize {
        self._query(r) - self._query(l)
    }
}
