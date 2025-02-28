//! core logic only
//! submission: https://codeforces.com/problemset/submission/932/291809529
const MULTIPLE_TEST: bool = false;

fn bsearch(mut lo: usize, mut hi: usize, cond: impl Fn(usize) -> bool) -> usize {
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        if cond(mid) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    hi
}

fn solver(q: usize, scanner: &mut Scanner) -> impl Printable {
    let n = 64 - q.leading_zeros() as usize;
    let ancestor = |lift: &[Vec<usize>], mut cur: usize, dist: usize| {
        for i in (0..n).rev() {
            if dist & (1 << i) != 0 {
                cur = lift[cur][i];
            }
        }
        cur
    };

    let mut lift = vec![vec![0; n], vec![0; n]];
    let mut weight = vec![usize::MAX, 0];
    let mut length = vec![0, 1];
    let mut presum = vec![0, 0];
    let mut last = 0;
    let mut ans = vec![];
    for (t, p, q) in scanner.iter::<(u8, usize, usize)>(q) {
        if t == 1 {
            let (r, w) = ((p ^ last), q ^ last);
            weight.push(w);
            let dist = bsearch(0, length[r], |dist| {
                let p = ancestor(&lift, r, dist);
                weight[p] < w
            });
            let parent = ancestor(&lift, r, dist);
            let sum = w + presum[parent];
            presum.push(sum);
            let len = length[parent] + 1;
            length.push(len);
            let mut l = vec![0; n];
            l[0] = parent;
            for i in 1..n {
                l[i] = lift[l[i - 1]][i - 1];
            }
            lift.push(l);
        } else {
            let (r, x) = ((p ^ last), q ^ last);
            let len = bsearch(1, length[r] + 1, |dist| {
                let p = ancestor(&lift, r, dist);
                let sum = presum[r] - presum[p];
                sum <= x
            }) - 1;
            last = len;
            ans.push(len);
        }
    }
    Sep::<_, '\n'>(ans)
}
