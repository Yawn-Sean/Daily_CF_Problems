//! core logic only
//! submission: https://codeforces.com/problemset/submission/615/302431153
const MULTIPLE_TEST: bool = false;

fn solver(s: String, t: String) -> impl Printable {
    let (s, t) = (s.into_bytes(), t.into_bytes());
    let (n, m) = (s.len(), t.len());
    let mut lcp = vec![vec![0i32; m + 1]; n + 1];
    let mut longest_match_len = vec![0; m];
    let mut longest_match_start = vec![0; m];

    for (i, &si) in s.iter().enumerate().rev() {
        for (j, &tj) in t.iter().enumerate().rev() {
            if si == tj {
                let matched = lcp[i + 1][j + 1] + 1;
                if longest_match_len[j] < matched {
                    longest_match_len[j] = matched;
                    longest_match_start[j] = i as i32;
                }
                lcp[i][j] = matched;
            }
        }
    }

    lcp = vec![vec![0i32; m + 1]; n + 1];
    for (i, &si) in s.iter().enumerate() {
        for (j, &tj) in t.iter().enumerate().rev() {
            if si == tj {
                let matched = lcp[i][j + 1] + 1;
                if longest_match_len[j].abs() < matched {
                    longest_match_len[j] = -matched;
                    longest_match_start[j] = i as i32;
                }
                lcp[i + 1][j] = matched;
            }
        }
    }

    let mut ans = vec![];
    let mut cur = 0;
    while cur < m {
        if longest_match_len[cur] == 0 {
            return Err(-1);
        }
        let start = longest_match_start[cur] + 1;
        let mut end = start + longest_match_len[cur];
        end += if end < start { 1 } else { -1 };
        ans.push((start, end));
        cur += longest_match_len[cur].abs() as usize;
    }
    Ok(ans.len().cr().then(Sep::<_, '\n'>(ans)))
}
