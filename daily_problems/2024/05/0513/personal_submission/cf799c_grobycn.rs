// core logic only
// submission: https://codeforces.com/problemset/submission/799/260818879
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, c: usize, d: usize, scanner: &mut Scanner) -> impl Printable {
    let (mut f1, mut f2): (Vec<_>, Vec<_>) = scanner
        .iter::<(usize, usize, char)>(n)
        .partition(|&(_, _, ty)| ty == 'C');
    f1.sort_unstable_by_key(|f| f.1);
    f2.sort_unstable_by_key(|f| f.1);
    let ans = find_max_beauty1(&f1, c)
        .and_then(|mxb1| find_max_beauty1(&f2, d).map(|mxb2| mxb1 + mxb2))
        .unwrap_or(0);
    ans.max(find_max_beauty2(&f1, c))
        .max(find_max_beauty2(&f2, d))
}

fn find_max_beauty1(xs: &[(usize, usize, char)], max_cost: usize) -> Option<usize> {
    xs.iter()
        .filter_map(|x| if x.1 <= max_cost { Some(x.0) } else { None })
        .max()
}

fn find_max_beauty2(xs: &[(usize, usize, char)], max_cost: usize) -> usize {
    let n = xs.len();
    let mut premax = Vec::with_capacity(n);
    let mut mx = 0;
    for &(b, _, _) in xs {
        mx = mx.max(b);
        premax.push(mx);
    }
    let mut ans = 0;
    for (i, &(b, p, _)) in xs.iter().enumerate() {
        let j = xs[..i].partition_point(|&(_, pj, _)| pj + p <= max_cost);
        if j > 0 {
            ans = ans.max(b + premax[j - 1]);
        }
    }
    ans
}
