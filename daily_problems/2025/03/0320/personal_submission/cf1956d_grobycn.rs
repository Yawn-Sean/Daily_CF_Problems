//! core logic only
//! submission: https://codeforces.com/problemset/submission/1956/311543738
const MULTIPLE_TEST: bool = false;

fn solver(mut a: Vec<u32>) -> impl Printable {
    let n = a.len();
    let mut max_sum = 0;
    let mut mask_keep = 0;
    for msk in 0..1 << n {
        let mut c = 0;
        let mut s = 0;
        for (i, &ai) in a.iter().enumerate() {
            if msk & (1 << i) != 0 {
                s += c * c + ai;
                c = 0;
            } else {
                c += 1;
            }
        }
        s += c * c;
        if s > max_sum {
            max_sum = s;
            mask_keep = msk;
        }
    }

    fn maximize(l: usize, r: usize, a: &mut [u32], ops: &mut Vec<(usize, usize)>) {
        if l == r {
            if a[l] > 1 {
                ops.push((l + 1, r + 1));
                a[l] = 0;
            }
            if a[l] == 0 {
                ops.push((l + 1, r + 1));
                a[l] = 1;
            }
            return;
        }
        for i in (l..r).rev() {
            maximize(l, i, a, ops);
        }
        if a[r] != 0 {
            ops.push((r + 1, r + 1));
        }
        ops.push((l + 1, r + 1));
        let mex = (r - l) as u32 + 1;
        a[l..=r].iter_mut().for_each(|ai| *ai = mex);
    }

    let mut ops = vec![];
    let mut l = 0;
    for r in 0..n {
        if mask_keep & (1 << r) != 0 {
            if l + 1 <= r {
                maximize(l, r - 1, &mut a, &mut ops);
            }
            l = r + 1;
        }
    }
    if l + 1 <= n {
        maximize(l, n - 1, &mut a, &mut ops);
    }
    (max_sum, ops.len()).cr().then(Sep::<_, '\n'>(ops))
}
