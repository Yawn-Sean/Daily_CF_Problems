// core logic only
// submission: https://codeforces.com/contest/954/submission/259101811
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, avg_t: usize, scanner: &mut Scanner) -> impl Printable {
    use std::cmp::Ordering;

    let a: Vec<usize> = scanner.iter(n).collect();
    let t: Vec<usize> = scanner.iter(n).collect();
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_unstable_by_key(|&i| t[i]);
    if t[indices[0]] > avg_t || avg_t > t[indices[n - 1]] {
        return 0.0;
    }
    let mut sum_x = 0;
    let mut sum_xt = 0;
    for (ai, ti) in indices.iter().map(|&i| (a[i], t[i])) {
        sum_x += ai;
        sum_xt += ai * ti;
    }
    match sum_xt.cmp(&(sum_x * avg_t)) {
        Ordering::Equal => sum_x as f64,
        Ordering::Less => {
            for (ai, ti) in indices.iter().map(|&i| (a[i], t[i])) {
                sum_x -= ai;
                sum_xt -= ai * ti;
                if sum_xt >= sum_x * avg_t {
                    // (sum_xt + x * ti) / (sum_x + x) == avg_t
                    // sum_xt + x * ti == avg_t * (sum_x + x)
                    // sum_xt - avg_t * sum_x == (avg_t - ti) * x
                    let x = ((sum_xt - sum_x * avg_t) as f64) / ((avg_t - ti) as f64);
                    return sum_x as f64 + x;
                }
            }
            unreachable!()
        }
        Ordering::Greater => {
            for (ai, ti) in indices.iter().map(|&i| (a[i], t[i])).rev() {
                sum_x -= ai;
                sum_xt -= ai * ti;
                if sum_xt <= sum_x * avg_t {
                    let x = ((sum_x * avg_t - sum_xt) as f64) / ((ti - avg_t) as f64);
                    return sum_x as f64 + x;
                }
            }
            unreachable!()
        }
    }
}
