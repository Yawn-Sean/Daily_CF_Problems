//! core logic only
//! submission: https://codeforces.com/problemset/submission/250/299914578
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, a: i64, b: i64, scanner: &mut Scanner) -> impl Printable {
    let west: Vec<i64> = scanner.iter(n).collect();
    let east: Vec<i64> = scanner.iter(m).collect();
    let ls: Vec<i64> = scanner.iter(m).collect();

    let dist = |i: usize, j: usize| {
        let yw = west[i];
        let ye = east[j];
        let l = ls[j];
        (((ye - yw) * (ye - yw) + (b - a) * (b - a)) as f64).sqrt()
            + ((a * a + yw * yw) as f64).sqrt()
            + l as f64
    };

    let mut best = 1e9;
    let mut ans = (0, 0);
    let mut i = 0;
    for j in 0..m {
        let mut mn = 1e9;
        while i < n {
            let d = dist(i, j);
            if d < mn {
                mn = d;
                i += 1;
            } else {
                break;
            }
        }
        i -= 1;
        if mn < best {
            best = mn;
            ans = (i + 1, j + 1);
        }
    }
    ans
}
