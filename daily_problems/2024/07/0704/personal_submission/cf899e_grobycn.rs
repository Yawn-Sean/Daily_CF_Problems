// core logic only
// submission: https://codeforces.com/contest/899/submission/268792200
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<usize>) -> impl Printable {
    use std::cmp::Reverse;
    use std::collections::BinaryHeap;

    let n = a.len();
    let mut prev = vec![usize::MAX; n];
    let mut next = vec![usize::MAX; n];
    let mut count = vec![0; n];

    let mut hp = BinaryHeap::new();
    let mut i = 0;
    while i < n {
        let x = a[i];
        let mut e = i + 1;
        while e < n && a[e] == x {
            e += 1;
        }
        let cnt = e - i;
        count[i] = cnt;
        if e < n {
            prev[e] = i;
            next[i] = e;
        }
        hp.push((cnt, Reverse(i)));
        i = e;
    }

    let mut ans = 0;
    while let Some((cnt, Reverse(idx))) = hp.pop() {
        if count[idx] == cnt {
            count[idx] = 0;
            ans += 1;
            let pre = prev[idx];
            let nxt = next[idx];
            if pre < n {
                next[pre] = nxt;
            }
            if nxt < n {
                prev[nxt] = pre;
            }
            if pre < n && nxt < n && a[pre] == a[nxt] {
                count[pre] += count[nxt];
                count[nxt] = 0;
                hp.push((count[pre], Reverse(pre)));
                let nxt = next[nxt];
                next[pre] = nxt;
                if nxt < n {
                    prev[nxt] = pre;
                }
            }
        }
    }
    ans
}
