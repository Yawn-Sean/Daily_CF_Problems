//! core logic only
//! submission: https://codeforces.com/problemset/submission/641/286227748
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut queries = std::collections::HashMap::new();
    for (i, (a, t, x)) in scanner.iter::<(u8, usize, usize)>(n).enumerate() {
        queries.entry(x).or_insert(vec![]).push((i, a, t));
    }

    let mut ans = vec![];
    for qs in queries.values() {
        let mut ts = qs.iter().map(|q| q.2).collect::<Vec<_>>();
        ts.sort_unstable();
        let mut tr = Fenwick::new(ts.len());
        for &(i, a, t) in qs {
            let tidx = ts.partition_point(|&ti| ti < t);
            match a {
                1 => tr.add(tidx, 1),
                2 => tr.add(tidx, -1),
                _ => ans.push((i, tr.query(tidx))),
            }
        }
    }
    ans.sort_unstable_by_key(|a| a.0);
    Sep::<_, '\n'>(ans.into_iter().map(|a| a.1))
}

struct Fenwick {
    arr: Vec<i32>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    fn add(&mut self, mut i: usize, v: i32) {
        while i < self.arr.len() {
            self.arr[i] += v;
            i += (i + 1) & !i;
        }
    }
    fn query(&mut self, mut r: usize) -> i32 {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
}
