//! core logic only
//! submission: https://codeforces.com/problemset/submission/167/303232122
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, l: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    if n < l {
        return 0.0;
    }
    let prob: Vec<u8> = scanner.iter(n).collect();
    let prize: Vec<i16> = scanner.iter(n).collect();

    let mut dp = vec![vec![0.0; 201]; n + 1];
    dp[0][k] = 1.0;
    let mut temp = vec![vec![0.0; 201]; n + 1];

    for (&p, &sz) in prob.iter().zip(&prize) {
        if sz != -1 {
            let p1 = (p as f64) / 100.0;
            let p2 = 1.0 - p1;
            let sz = sz as usize;
            for cnt in 0..=n {
                for cap in 0..=200 {
                    temp[cnt][cap] += dp[cnt][cap] * p2;
                    if cnt < n {
                        let ncap = (cap + sz).min(200);
                        let ncnt = cnt + 1;
                        temp[ncnt][ncap] += dp[cnt][cap] * p1;
                    }
                }
            }
            std::mem::swap(&mut dp, &mut temp);
            temp.iter_mut()
                .map(|r| r.iter_mut())
                .flatten()
                .for_each(|x| *x = 0.0);
        }
    }

    for (&p, &sz) in prob.iter().zip(&prize) {
        if sz == -1 {
            let p1 = (p as f64) / 100.0;
            let p2 = 1.0 - p1;
            for cnt in 0..=n {
                for cap in 0..=200 {
                    temp[cnt][cap] += dp[cnt][cap] * p2;
                    if cap > 0 && cnt < n {
                        let ncap = cap - 1;
                        let ncnt = cnt + 1;
                        temp[ncnt][ncap] = dp[cnt][cap] * p1;
                    }
                }
            }
            std::mem::swap(&mut dp, &mut temp);
            temp.iter_mut()
                .map(|r| r.iter_mut())
                .flatten()
                .for_each(|x| *x = 0.0);
        }
    }

    dp[l..=n].iter().map(|r| r.iter()).flatten().sum::<f64>()
}
