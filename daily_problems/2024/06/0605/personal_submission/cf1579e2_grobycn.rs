// core logic only
// submission: https://codeforces.com/contest/1579/submission/264255364
const MULTIPLE_TEST: bool = true;

fn solver(a: Vec<i32>) -> impl Printable {
    let mut sorted = a.clone();
    sorted.sort_unstable();
    sorted.dedup();
    let m = sorted.len();
    let ord = |x: i32| sorted.partition_point(|&y| y < x);
    let mut ans = 0;
    let mut tr = Fenwick::new(m);
    for x in a {
        let i = ord(x);
        ans += tr._query(i).min(tr.query(i + 1, m));
        tr.inc(i, 1);
    }
    ans
}

struct Fenwick {
    arr: Vec<i64>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
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
    fn query(&self, l: usize, r: usize) -> i64 {
        self._query(r) - self._query(l)
    }
    fn inc(&mut self, mut i: usize, d: i64) {
        i += 1;
        while i <= self.arr.len() {
            self.arr[i - 1] += d;
            i += i & !(i - 1);
        }
    }
}
