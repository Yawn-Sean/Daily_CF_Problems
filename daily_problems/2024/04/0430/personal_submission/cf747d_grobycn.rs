// core logic only
// submission: https://codeforces.com/problemset/submission/747/258842838
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut dist = vec![];
    let mut last = 0;
    let mut cnt = 0;
    for (i, t) in scanner.iter::<i8>(n).enumerate() {
        if t < 0 {
            cnt += 1;
            if cnt > k {
                return Err(-1);
            }
            if cnt > 1 {
                dist.push(i - last - 1);
            }
            last = i;
        }
    }

    if cnt == 0 {
        return Ok(0);
    }

    dist.sort_unstable();

    let mut ans = (dist.len() + 1) * 2;
    let mut rest = k - dist.len() - 1;
    for d in dist {
        if rest < d {
            break;
        }
        rest -= d;
        ans -= 2;
    }
    if rest >= n - 1 - last {
        ans -= 1;
    }
    Ok(ans)
}
