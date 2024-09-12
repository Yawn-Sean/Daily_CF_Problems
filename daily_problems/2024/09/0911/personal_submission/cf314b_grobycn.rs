//! core logic only
//! submission: https://codeforces.com/problemset/submission/314/280741775
const MULTIPLE_TEST: bool = false;

fn solver(b: usize, d: usize, a: String, c: String) -> impl Printable {
    let (a, c) = (a.as_bytes(), c.as_bytes());
    let (n, m) = (a.len(), c.len());
    let mut next = Vec::with_capacity(m);
    let mut count = Vec::with_capacity(m);
    for start in 0..m {
        let mut i = start;
        let mut cnt = 0;
        for &b in a.iter() {
            if b == c[i] {
                i += 1;
                if i == m {
                    cnt += 1;
                    i = 0;
                }
            }
        }
        if i == start && cnt == 0 {
            return 0;
        }
        next.push(i);
        count.push(cnt);
    }
    let mut pd = 0;
    let mut i = 0;
    for _ in 0..b {
        pd += count[i];
        i = next[i];
    }
    pd / d
}
