//! core logic only
//! submission: https://codeforces.com/problemset/submission/109/321384528
const MULTIPLE_TEST: bool = false;

fn solver(pl: usize, pr: usize, vl: usize, vr: usize, k: usize) -> impl Printable {
    let mut lucky_numbers = Vec::with_capacity(1 << 10);
    lucky_numbers.push(0);
    for len in 1..=9 {
        for msk in 0..1 << len {
            let mut num = 0;
            let mut unit = 1;
            for i in 0..len {
                if msk & (1 << i) == 0 {
                    num += 4 * unit;
                } else {
                    num += 7 * unit;
                }
                unit *= 10;
            }
            lucky_numbers.push(num);
        }
    }
    lucky_numbers.push(1_000_000_001);

    let intersect = |(l1, r1): (usize, usize), (l2, r2): (usize, usize)| {
        if r1 < l2 || r2 < l1 {
            return 0;
        }
        r2.min(r1) + 1 - l2.max(l1)
    };

    let total = (pr + 1 - pl) * (vr + 1 - vl);
    let mut cnt = 0;
    for w in lucky_numbers.windows(k + 2) {
        let (low_min, low_max) = (w[0] + 1, w[1]);
        let (high_min, high_max) = (w[k], w[k + 1] - 1);
        cnt += intersect((low_min, low_max), (pl, pr)) * intersect((high_min, high_max), (vl, vr));
        cnt += intersect((low_min, low_max), (vl, vr)) * intersect((high_min, high_max), (pl, pr));
    }
    if k == 1 {
        cnt -= lucky_numbers
            .into_iter()
            .filter(|&x| pl <= x && x <= pr && vl <= x && x <= vr)
            .count();
    }
    (cnt as f64) / (total as f64)
}
