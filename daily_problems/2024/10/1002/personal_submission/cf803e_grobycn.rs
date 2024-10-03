//! core logic only
//! submission: https://codeforces.com/problemset/submission/803/283975736
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, k: usize, s: String) -> impl Printable {
    let mut s = s.into_bytes();
    if s[n - 1] == b'D' {
        return Err("NO");
    }
    let mut from = vec![vec![0; 2 * k + 1]; n + 1];
    let mut queue = std::collections::VecDeque::from([(0, k)]);
    while let Some((cur, delta)) = queue.pop_front() {
        if cur == n {
            continue;
        }
        if s[cur] == b'D' || s[cur] == b'?' {
            if from[cur + 1][delta] == 0 {
                queue.push_back((cur + 1, delta));
                from[cur + 1][delta] = b'D';
            }
        }
        if s[cur] == b'W' || s[cur] == b'?' {
            if delta + 1 < 2 * k || cur == n - 1 {
                if from[cur + 1][delta + 1] == 0 {
                    queue.push_back((cur + 1, delta + 1));
                    from[cur + 1][delta + 1] = b'W';
                }
            }
        }
        if s[cur] == b'L' || s[cur] == b'?' {
            if delta > 1 || cur == n - 1 {
                if from[cur + 1][delta - 1] == 0 {
                    queue.push_back((cur + 1, delta - 1));
                    from[cur + 1][delta - 1] = b'L';
                }
            }
        }
    }
    if from[n][2 * k] == 0 && from[n][0] == 0 {
        return Err("NO");
    }
    let mut delta = if from[n][0] == 0 { 2 * k } else { 0 };
    for i in (0..n).rev() {
        s[i] = from[i + 1][delta];
        match s[i] {
            b'W' => delta -= 1,
            b'L' => delta += 1,
            _ => {}
        }
    }
    Ok(unsafe { String::from_utf8_unchecked(s) })
}
