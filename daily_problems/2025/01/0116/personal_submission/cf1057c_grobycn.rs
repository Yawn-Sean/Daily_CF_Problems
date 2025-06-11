//! core logic only
//! submission: https://codeforces.com/problemset/submission/1057/301252729
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, mut s: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let rs: Vec<usize> = scanner.iter(n).collect();
    let cs: Vec<_> = String::from_scanner(scanner).into_bytes();
    let mut dist = vec![vec![usize::MAX; n]; k + 1];
    s -= 1;
    dist[0][s - 1] = 0;
    for (i, (&ri, &ci)) in rs.iter().zip(&cs).enumerate() {
        dist[ri][i] = s.abs_diff(i);
    }

    for sum in 0..k {
        for last in 0..n {
            if dist[sum][last] == usize::MAX {
                continue;
            }
            for (i, (&ri, &ci)) in rs.iter().zip(&cs).enumerate() {
                if ri > rs[last] && ci != cs[last] {
                    let d = dist[sum][last] + i.abs_diff(last);
                    let sum = (sum + ri).min(k);
                    dist[sum][i] = dist[sum][i].min(d);
                }
            }
        }
    }
    let ans = *dist[k].iter().min().unwrap();
    if ans == usize::MAX {
        Err(-1)
    } else {
        Ok(ans)
    }
}
