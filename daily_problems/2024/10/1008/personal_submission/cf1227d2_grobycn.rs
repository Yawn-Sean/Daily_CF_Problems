//! core logic only
//! submission: https://codeforces.com/contest/1227/submission/284906612
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<i32>, requests: Vec<(usize, usize)>) -> impl Printable {
    let n = a.len();
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_by_key(|&i| -a[i]);
    let m = requests.len();
    let mut request_indices: Vec<_> = (0..m).collect();
    request_indices.sort_unstable_by_key(|&i| requests[i].0);
    let mut ans = vec![0; m];
    let mut seq_len = 0;
    let mut tr = Fenwick::new(n);
    for &i in &request_indices {
        let (k, pos) = requests[i];
        while seq_len < k {
            let idx = indices[seq_len];
            tr.inc1(idx);
            seq_len += 1;
        }
        let (mut lo, mut hi) = (0, n);
        while lo < hi {
            let mid = (hi - lo) / 2 + lo;
            if tr.query(mid) >= pos {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        ans[i] = a[hi - 1];
    }
    Sep::<_, '\n'>(ans)
}

struct Fenwick {
    arr: Vec<usize>,
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
    // sum of 0..r
    fn query(&self, mut r: usize) -> usize {
        let mut ret = 0;
        while r > 0 {
            ret += self.arr[r - 1];
            r &= r - 1;
        }
        ret
    }
}
