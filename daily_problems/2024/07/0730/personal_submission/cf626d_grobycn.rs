//! core logic only
//! submission: https://codeforces.com/problemset/submission/626/273514178
const MULTIPLE_TEST: bool = false;

fn solver(balls: Vec<usize>) -> impl Printable {
    let (mut mx, mut mn) = (usize::MIN, usize::MAX);
    for &x in &balls {
        mx = mx.max(x);
        mn = mn.min(x);
    }
    let max_delta = mx - mn;
    let mut prob = vec![0u128; max_delta + 1];
    for (i, &x) in balls.iter().enumerate() {
        for &y in &balls[..i] {
            prob[x.abs_diff(y)] += 1;
        }
    }

    let mut prob2 = vec![0; max_delta];
    for d1 in 1..max_delta {
        for d2 in 1..max_delta {
            if d1 + d2 >= max_delta {
                break;
            }
            prob2[d1 + d2] += prob[d1] * prob[d2];
        }
    }
    for i in 1..max_delta {
        prob2[i] += prob2[i - 1];
    }

    let mut ans = 0;
    for d3 in 1..=max_delta {
        ans += prob2[d3 - 1] * prob[d3];
    }

    let n = balls.len() as u128;
    ((ans * 8) as f64) / ((n * (n - 1)).pow(3) as f64)
}
