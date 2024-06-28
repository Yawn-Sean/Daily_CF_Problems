// core logic only
// submission: https://codeforces.com/problemset/submission/1321/267851078
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, s: String) -> impl Printable {
    let s = s.into_bytes();
    let mut prev = vec![0; n];
    let mut next = vec![n; n];
    for i in 0..n {
        prev[i] = i.wrapping_sub(1);
        next[i] = i + 1;
    }

    let mut del = vec![vec![]; 26];
    let mut mark = vec![false; n];
    for (i, &b) in s.iter().enumerate() {
        if (i > 0 && s[i - 1] + 1 == b) || (i + 1 < n && b == s[i + 1] + 1) {
            del[(b - b'a') as usize].push(i);
            mark[i] = true;
        }
    }

    let mut ans = 0;
    for i in (0..26).rev() {
        while let Some(idx) = del[i].pop() {
            ans += 1;
            let (pre, nxt) = (prev[idx], next[idx]);
            if nxt < n {
                prev[nxt] = pre;
            }
            if pre < n {
                next[pre] = nxt;
            }
            if pre < n && nxt < n {
                if !mark[nxt] && s[pre] + 1 == s[nxt] {
                    mark[nxt] = true;
                    del[(s[nxt] - b'a') as usize].push(nxt);
                }
                if !mark[pre] && s[nxt] + 1 == s[pre] {
                    mark[pre] = true;
                    del[(s[pre] - b'a') as usize].push(pre);
                }
            }
        }
    }
    ans
}
