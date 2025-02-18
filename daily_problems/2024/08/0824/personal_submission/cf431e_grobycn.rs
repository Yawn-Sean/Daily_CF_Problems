//! core logic only
//! submission: https://mirror.codeforces.com/problemset/submission/431/277929826
const MULTIPLE_TEST: bool = false;

enum Action {
    Modify(usize, i64),
    Query(i64),
}

impl FromScanner for Action {
    fn from_scanner(scanner: &mut Scanner) -> Self {
        if u8::from_scanner(scanner) == 1 {
            let (p, x) = <(usize, i64)>::from_scanner(scanner);
            Action::Modify(p - 1, x)
        } else {
            let v = i64::from_scanner(scanner);
            Action::Query(v)
        }
    }
}

fn solver(n: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::BTreeSet;
    let mut hs: Vec<i64> = scanner.iter(n).collect();
    let mut mp = BTreeSet::new();
    for &h in &hs {
        mp.insert(h);
    }
    let actions: Vec<Action> = scanner.iter(q).collect();
    for a in &actions {
        if let Action::Modify(_, x) = a {
            mp.insert(*x);
        }
    }

    let mp: Vec<_> = mp.into_iter().collect();
    let indice = |x: i64| mp.binary_search(&x).unwrap();
    let m = mp.len();
    let mut ans = vec![];
    let mut tr = Fenwick::new(m);
    for &h in &hs {
        let i = indice(h);
        tr.add(i, 1, h);
    }
    for a in actions {
        match a {
            Action::Modify(p, mut x) => {
                tr.add(indice(x), 1, x);
                std::mem::swap(&mut hs[p], &mut x);
                tr.add(indice(x), -1, -x);
            }
            Action::Query(v) => {
                let (mut lo, mut hi) = (1, m + 1);
                let mut extra = 0.0;
                while lo < hi {
                    let mid = (hi - lo) / 2 + lo;
                    let (cnt, sum) = tr._query(mid);
                    let d = mp[mid - 1] * cnt - sum - v;
                    if d >= 0 {
                        hi = mid;
                    } else {
                        extra = (-d as f64) / (cnt as f64);
                        lo = mid + 1;
                    }
                }
                ans.push(mp[hi - 2] as f64 + extra);
            }
        }
    }
    Sep::<_, '\n'>(ans)
}

struct Fenwick {
    count: Vec<i64>,
    sum: Vec<i64>,
}

impl Fenwick {
    pub fn new(n: usize) -> Self {
        Self {
            count: vec![0; n],
            sum: vec![0; n],
        }
    }
    pub fn add(&mut self, mut i: usize, c: i64, h: i64) {
        while i < self.count.len() {
            self.count[i] += c;
            self.sum[i] += h;
            i += (i + 1) & !i;
        }
    }
    pub fn _query(&self, mut r: usize) -> (i64, i64) {
        let (mut cnt, mut sum) = (0, 0);
        while r > 0 {
            cnt += self.count[r - 1];
            sum += self.sum[r - 1];
            r &= r - 1;
        }
        (cnt, sum)
    }
}
