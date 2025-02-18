type Point = ((i32, i32, i32), usize);

fn main() {
    input! { n: usize }
    input! { points: [(i32, i32, i32); n] }
    let mut points_with_index: Vec<((i32, i32, i32), usize)> = points
        .iter()
        .enumerate()
        .map(|(a, b)| (*b, a))
        .collect::<Vec<_>>();
    points_with_index.sort_by_key(|k| k.0);

    let mut removed = vec![false; n];

    let mut res = vec![];

    fn deal(
        points_with_index: &[Point],
        removed: &mut [bool],
        res: &mut Vec<(usize, usize)>,
        check: fn(usize, usize, &[Point]) -> bool,
        n: usize,
    ) {
        let mut pre = 0;
        while pre < n && removed[pre] {
            pre += 1;
        }
        let mut cur = pre + 1;
        while cur < n && removed[cur] {
            cur += 1;
        }
        while cur < n {
            if check(pre, cur, points_with_index) {
                res.push((points_with_index[pre].1 + 1, points_with_index[cur].1 + 1));
                removed[pre] = true;
                removed[cur] = true;
                pre = cur;
                cur += 1;
                while cur < n && removed[cur] {
                    cur += 1;
                }
            }
            pre = cur;
            cur += 1;
            while cur < n && removed[cur] {
                cur += 1;
            }
        }
    }
    deal(
        &points_with_index,
        &mut removed,
        &mut res,
        |pre, cur, points| points[pre].0 == points[cur].0,
        n,
    );
    deal(
        &points_with_index,
        &mut removed,
        &mut res,
        |pre, cur, points| {
            points[pre].0 .0 == points[cur].0 .0 && points[pre].0 .1 == points[cur].0 .1
        },
        n,
    );
    deal(
        &points_with_index,
        &mut removed,
        &mut res,
        |pre, cur, points| points[pre].0 .0 == points[cur].0 .0,
        n,
    );
    deal(
        &points_with_index,
        &mut removed,
        &mut res,
        |pre, cur, points| true,
        n,
    );
    // println!("{}", res.len());
    for (a, b) in res {
        println!("{} {}", a, b);
    }
}
