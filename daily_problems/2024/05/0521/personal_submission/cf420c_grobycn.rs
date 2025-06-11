// core logic only
// submission: https://codeforces.com/problemset/submission/420/262032885
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, p: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    for (mut x, mut y) in scanner.iter::<(usize, usize)>(n) {
        (x, y) = (x - 1, y - 1);
        adj[x].push(y);
        adj[y].push(x);
    }

    let mut ans = 0;
    let mut tr = Fenwick::new(n + 1);
    let mut count = adj.iter().map(|ys| ys.len()).collect::<Vec<_>>();
    for ys in adj.iter() {
        tr.inc(ys.len(), 1);
    }

    for ys in adj.iter() {
        if ys.len() >= p {
            // pair with any one
            ans += n as i64 - 1;
            continue;
        }
        for &y in ys {
            tr.inc(count[y], -1);
            count[y] -= 1;
            tr.inc(count[y], 1);
        }
        let t = p - ys.len();
        ans += tr.query(t, n + 1);
        if ys.len() >= t {
            ans -= 1;
        }
        for &y in ys {
            tr.inc(count[y], -1);
            count[y] += 1;
            tr.inc(count[y], 1);
        }
    }
    ans / 2
}

struct Fenwick {
    arr: Vec<i64>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    // query sum of 0..r
    fn _query(&self, mut r: usize) -> i64 {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
    // query sum of l..r
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
