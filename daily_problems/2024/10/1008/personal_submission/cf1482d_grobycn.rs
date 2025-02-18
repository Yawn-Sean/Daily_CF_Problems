//! core logic only
//! submission: https://codeforces.com/problemset/submission/1482/284922566
const MULTIPLE_TEST: bool = true;

fn solver(a: Vec<usize>) -> impl Printable {
    let n = a.len();
    let mut next: Vec<_> = (1..=n).map(|i| i % n).collect();
    let mut prev: Vec<_> = (0..n).map(|i| (i + n - 1) % n).collect();
    let mut dq: std::collections::VecDeque<_> = (0..n).collect();
    let mut ans = vec![];
    let mut deleted = vec![false; n];
    while let Some(i) = dq.pop_front() {
        if deleted[i] {
            continue;
        }
        let nxt = next[i];
        if gcd(a[i], a[nxt]) == 1 {
            ans.push(nxt + 1);
            next[i] = next[nxt];
            deleted[nxt] = true;
            prev[next[i]] = i;
            dq.push_back(i);
        }
    }
    (ans.len(), Sep::<_, ' '>(ans))
}

fn gcd(mut a: usize, mut b: usize) -> usize {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t
    }
    a
}
