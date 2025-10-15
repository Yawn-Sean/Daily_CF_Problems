//! core logic only
//! submission: https://codeforces.com/problemset/submission/488/312334286
const MULTIPLE_TEST: bool = false;

fn solver(mut xs: Vec<u32>) -> impl Printable {
    xs.sort_unstable();
    let ans = match xs[..] {
        [] => vec![1, 1, 3, 3],
        [x] => vec![x, 3 * x, 3 * x],
        [x, y] => {
            if 3 * x < y {
                return Err("NO");
            }
            vec![4 * x - y, 3 * x]
        }
        [x, y, z] => {
            if 3 * x == z {
                vec![4 * x - y]
            } else if y + z == 4 * x {
                vec![3 * x]
            } else if z % 3 == 0 && z / 3 + z == x + y {
                vec![z / 3]
            } else {
                return Err("NO");
            }
        }
        [x, y, z, u] => {
            if x * 3 != u || y + z != 4 * x {
                return Err("NO");
            }
            return Err("YES");
        }
        _ => unreachable!(),
    };
    Ok("YES".cr().then(Sep::<_, '\n'>(ans)))
}
