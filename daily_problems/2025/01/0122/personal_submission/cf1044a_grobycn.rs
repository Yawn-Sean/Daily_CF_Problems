//! core logic only
//! submission: https://codeforces.com/problemset/submission/1044/302438124
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut vert: Vec<i32> = scanner.iter(n).collect();
    vert.sort_unstable();
    let mut horiz = scanner
        .iter::<(i32, i32, i32)>(m)
        .filter_map(|(x1, x2, _)| if x1 == 1 { Some(x2) } else { None })
        .collect::<Vec<_>>();
    horiz.sort_unstable();

    let m = horiz.len();
    let mut ans = n + m;
    let mut idx = 0;
    for (i, x) in vert.into_iter().chain([1_000_000_000]).enumerate() {
        while idx < m && horiz[idx] < x {
            idx += 1;
        }
        ans = ans.min(i + m - idx);
    }
    ans
}
