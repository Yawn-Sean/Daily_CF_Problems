//! core logic only
//! submission: https://codeforces.com/problemset/submission/331/296852812
const MULTIPLE_TEST: bool = false;

fn solver(mut perm: Vec<usize>, q: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashSet;
    let n = perm.len();
    let mut indice = vec![0; n];
    for (i, p) in perm.iter_mut().enumerate() {
        *p -= 1;
        indice[*p] = i;
    }

    let mut ans = vec![];
    let mut tr = Fenwick::new(n - 1);
    for (i, w) in indice.windows(2).enumerate() {
        if w[0] > w[1] {
            tr.inc(i, 1);
        }
    }

    for (p, mut x, mut y) in scanner.iter::<(u8, usize, usize)>(q) {
        (x, y) = (x - 1, y - 1);
        if p == 1 {
            ans.push(tr.query(x, y) + 1);
        } else {
            let (ix, iy) = (perm[x], perm[y]);
            let check_points = HashSet::from([ix.saturating_sub(1), ix, iy.saturating_sub(1), iy]);
            for &i in &check_points {
                if i + 1 < n && indice[i] > indice[i + 1] {
                    tr.inc(i, -1);
                }
            }
            perm.swap(x, y);
            indice.swap(ix, iy);
            for &i in &check_points {
                if i + 1 < n && indice[i] > indice[i + 1] {
                    tr.inc(i, 1);
                }
            }
        }
    }
    Sep::<_, '\n'>(ans)
}

struct Fenwick {
    arr: Vec<i32>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    fn inc(&mut self, mut i: usize, d: i32) {
        while i < self.arr.len() {
            self.arr[i] += d;
            i += (i + 1) & !i;
        }
    }
    fn _query(&self, mut r: usize) -> i32 {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
    fn query(&self, l: usize, r: usize) -> i32 {
        self._query(r) - self._query(l)
    }
}
