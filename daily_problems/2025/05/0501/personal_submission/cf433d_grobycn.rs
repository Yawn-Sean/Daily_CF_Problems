//! core logic only
//! submission: https://codeforces.com/problemset/submission/433/317925408
const MULTIPLE_TEST: bool = false;

fn accumulate_inplace<'a>(xs: impl Iterator<Item = u8>, acc: impl Iterator<Item = &'a mut usize>) {
    let mut sum = 0;
    for (x, acc) in xs.zip(acc) {
        if x == 0 {
            sum = 0;
        } else {
            sum += 1;
        }
        *acc = sum;
    }
}

fn max_rectangle_area(
    cnt1_left: impl Iterator<Item = usize>,
    cnt1_right: impl Iterator<Item = usize>,
) -> usize {
    let mut left = 0;
    let mut right = usize::MAX;
    let mut mx = 0;
    for ((c1l, c1r), h) in cnt1_left.take_while(|&c| c > 0).zip(cnt1_right).zip(1..) {
        let l = 1000 + 1 - c1l;
        let r = 1000 + c1r - 1;
        left = left.max(l);
        right = right.min(r);
        mx = mx.max((right + 1 - left) * h);
    }
    mx
}

fn solver(n: usize, m: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    let mut a: Vec<Vec<u8>> = (0..n).map(|_| scanner.iter(m).collect()).collect();
    let mut acc_l2r = vec![vec![0; m]; n];
    let mut acc_r2l = vec![vec![0; m]; n];
    let mut acc_t2b = vec![vec![0; m]; n];
    let mut acc_b2t = vec![vec![0; m]; n];

    for ((row, l2r), r2l) in a.iter().zip(&mut acc_l2r).zip(&mut acc_r2l) {
        accumulate_inplace(row.iter().copied(), l2r.iter_mut());
        accumulate_inplace(row.iter().rev().copied(), r2l.iter_mut().rev());
    }
    for c in 0..m {
        accumulate_inplace(
            a.iter().map(|row| row[c]),
            acc_t2b.iter_mut().map(|row| &mut row[c]),
        );
        accumulate_inplace(
            a.iter().rev().map(|row| row[c]),
            acc_b2t.iter_mut().rev().map(|row| &mut row[c]),
        );
    }

    let mut ans = vec![];
    for (op, mut x, mut y) in scanner.iter::<(u8, usize, usize)>(q) {
        (x, y) = (x - 1, y - 1);
        if op == 1 {
            a[x][y] ^= 1;
            accumulate_inplace(a[x].iter().copied(), acc_l2r[x].iter_mut());
            accumulate_inplace(a[x].iter().rev().copied(), acc_r2l[x].iter_mut().rev());
            accumulate_inplace(
                a.iter().map(|row| row[y]),
                acc_t2b.iter_mut().map(|row| &mut row[y]),
            );
            accumulate_inplace(
                a.iter().rev().map(|row| row[y]),
                acc_b2t.iter_mut().rev().map(|row| &mut row[y]),
            );
        } else {
            if a[x][y] == 0 {
                ans.push(0);
                continue;
            }
            let mx = max_rectangle_area(
                acc_l2r[x..].iter().map(|row| row[y]),
                acc_r2l[x..].iter().map(|row| row[y]),
            )
            .max(max_rectangle_area(
                acc_l2r[..=x].iter().rev().map(|row| row[y]),
                acc_r2l[..=x].iter().rev().map(|row| row[y]),
            ))
            .max(max_rectangle_area(
                acc_t2b[x][y..].iter().copied(),
                acc_b2t[x][y..].iter().copied(),
            ))
            .max(max_rectangle_area(
                acc_t2b[x][..=y].iter().rev().copied(),
                acc_b2t[x][..=y].iter().rev().copied(),
            ));
            ans.push(mx);
        }
    }
    Sep::<_, '\n'>(ans)
}
