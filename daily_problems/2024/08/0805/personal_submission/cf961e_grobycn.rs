//! core logic only
//! submission: https://codeforces.com/problemset/submission/961/274554014
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<usize>) -> impl Printable {
    let n = a.len();
    let mut tr = Fenwick::new(n);
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_unstable_by_key(|&i| a[i]);
    let mut iter = indices.into_iter().rev().peekable();
    let mut ans = 0;
    for (y, &ay) in a.iter().enumerate().rev() {
        while let Some(x) = iter.next_if(|&x| a[x] > y) {
            tr.inc1(x);
        }
        ans += tr._query(ay.min(n));
        if ay > y {
            ans -= 1;
        }
    }
    ans / 2
}

struct Fenwick {
    arr: Vec<usize>
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    fn inc1(&mut self, mut i: usize) {
        while i < self.arr.len() {
            self.arr[i] += 1;
            i += (i + 1) & !i;
        }
    }
    fn _query(&self, mut r: usize) -> usize {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
    fn query(&self, l: usize, r: usize) -> usize {
        self._query(r) - self._query(l)
    }
}
