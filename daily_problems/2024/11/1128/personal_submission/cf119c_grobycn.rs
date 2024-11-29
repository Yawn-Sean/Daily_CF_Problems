//! core logic only
//! submission: https://codeforces.com/problemset/submission/119/293664208
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut students: Vec<(usize, (usize, usize, usize))> = scanner.iter(m).enumerate().collect();
    students.sort_unstable_by_key(|s| s.1 .2);

    let mut dp = vec![vec![i64::MIN; 101]; m];
    let mut from = vec![vec![vec![[usize::MAX; 2]; 101]; m]; n];
    for (i, &(_, (a, b, _))) in students.iter().enumerate() {
        for x in a..=b {
            dp[i][x - a] = x as i64;
        }
    }
    for day in 2..=n {
        let mut ndp = vec![vec![i64::MIN; 101]; m];
        for (cur, &(_, (a, b, c))) in students.iter().enumerate() {
            for (last, &(_, (pa, pb, pc))) in students[..cur].iter().enumerate() {
                if pc >= c {
                    continue;
                }
                for px in pa..=pb {
                    if dp[last][px - pa] == i64::MIN {
                        continue;
                    }
                    for x in [px + k, px * k] {
                        if a <= x && x <= b {
                            let tot = dp[last][px - pa] + x as i64;
                            if tot > ndp[cur][x - a] {
                                ndp[cur][x - a] = tot;
                                from[day - 1][cur][x - a] = [last, px - pa];
                            }
                        }
                    }
                }
            }
        }
        dp = ndp;
    }

    let mut mx = i64::MIN;
    let mut mx_state = [usize::MAX, usize::MAX];
    for (last, row) in dp.iter().enumerate() {
        for (delta, &total) in row.iter().enumerate() {
            if mx < total {
                mx = total;
                mx_state = [last, delta];
            }
        }
    }
    if mx == i64::MIN {
        return Err("NO");
    }
    let mut ans = Vec::with_capacity(n);
    let [mut cur, mut delta] = mx_state;
    for prev in from.iter().rev() {
        ans.push((students[cur].0 + 1, students[cur].1 .0 + delta));
        [cur, delta] = prev[cur][delta];
    }
    ans.reverse();
    Ok("YES".cr().then(Sep::<_, '\n'>(ans)))
}
