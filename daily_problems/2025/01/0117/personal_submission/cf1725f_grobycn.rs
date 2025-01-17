//! core logic only
//! submission: https://codeforces.com/problemset/submission/1725/301371920
const MULTIPLE_TEST: bool = false;

fn solver(mut rows: Vec<(usize, usize)>, q: usize, scanner: &mut Scanner) -> impl Printable {
    let mut ms = vec![0; 30];
    for (i, m) in ms.iter_mut().enumerate().rev() {
        let k = 1 << i;
        let mut full = 0;
        let mut remaing = std::collections::BTreeMap::new();
        for &(l, r) in &rows {
            let len = r + 1 - l;
            if len >= k {
                full += 1;
            } else {
                let (l, r) = (l % k, r % k);
                *remaing.entry(l).or_insert(0) += 1;
                *remaing.entry(r + 1).or_insert(0) -= 1;
                if l > r {
                    *remaing.entry(k).or_insert(0) -= 1;
                    *remaing.entry(0).or_insert(0) += 1;
                }
            }
        }
        let mut sum = 0;
        let mut mx = 0;
        for &d in remaing.values() {
            sum += d;
            mx = mx.max(sum);
        }
        *m = mx + full;
    }

    let ans: Vec<_> = scanner
        .iter::<usize>(q)
        .map(|w| ms[w.trailing_zeros() as usize])
        .collect();
    Sep::<_, '\n'>(ans)
}
