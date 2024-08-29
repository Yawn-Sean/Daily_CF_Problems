//! core logic only
//! submission: https://codeforces.com/problemset/submission/1237/278402615
const MULTIPLE_TEST: bool = false;

fn solver(points: Vec<[i32; 3]>) -> impl Printable {
    fn remove_by_axis(
        ps: &[[i32; 3]],
        remain: &mut Vec<usize>,
        ans: &mut Vec<(usize, usize)>,
        axis: usize,
    ) {
        let mut gs = std::collections::HashMap::new();
        while let Some(i) = remain.pop() {
            let key = &ps[i][..axis];
            gs.entry(key).or_insert(vec![]).push(i);
        }
        for v in gs.values_mut() {
            v.sort_unstable_by_key(|&i| ps[i][axis]);
            while let Some(i) = v.pop() {
                match v.pop() {
                    Some(j) => ans.push((i + 1, j + 1)),
                    _ => remain.push(i),
                }
            }
        }
    }

    let n = points.len();
    let mut remain: Vec<_> = (0..n).collect();
    let mut ans = Vec::with_capacity(n / 2);
    remove_by_axis(&points, &mut remain, &mut ans, 2);
    remove_by_axis(&points, &mut remain, &mut ans, 1);
    remove_by_axis(&points, &mut remain, &mut ans, 0);
    Sep::<_, '\n'>(ans)
}
