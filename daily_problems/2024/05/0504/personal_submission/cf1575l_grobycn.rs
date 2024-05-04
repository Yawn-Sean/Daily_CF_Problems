// core logic only
// submission: https://codeforces.com/problemset/submission/1575/259447450
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut a: Vec<_> = scanner
        .iter::<usize>(n)
        .zip(1..)
        .filter_map(|(ai, i)| if ai > i { None } else { Some((ai, i - ai)) })
        .collect();
    a.sort_unstable_by_key(|&(ai, d)| (ai, std::cmp::Reverse(d)));
    let mut tr = Fenwick::new(n);
    for &(_, d) in a.iter() {
        let mx = tr.query_max(d + 1);
        tr.update(d, mx + 1);
    }
    tr.query_max(n)
}

struct Fenwick {
    arr: Vec<usize>,
}

impl Fenwick {
    fn new(n: usize) -> Self {
        Self { arr: vec![0; n] }
    }
    fn update(&mut self, mut i: usize, val: usize) {
        i += 1;
        while i <= self.arr.len() && val > self.arr[i - 1] {
            self.arr[i - 1] = val;
            i += i & !(i - 1);
        }
    }
    // query max of [..r]
    fn query_max(&mut self, mut r: usize) -> usize {
        let mut ret = 0;
        while r > 0 {
            ret = ret.max(self.arr[r - 1]);
            r &= r - 1;
        }
        ret
    }
}
