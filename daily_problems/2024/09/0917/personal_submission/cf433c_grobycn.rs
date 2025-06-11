//! core logic only
//! submission: https://codeforces.com/problemset/submission/433/281611353
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, a: Vec<usize>) -> impl Printable {
    let mut neighbors = vec![vec![]; n + 1];
    let mut nop_turn = 0;
    let mut old = vec![0; n + 1];
    for w in a.windows(2) {
        if let [a, b] = w[..] {
            if a == b {
                continue;
            }
            neighbors[a].push(b);
            neighbors[b].push(a);
            let d = a.abs_diff(b);
            nop_turn += d;
            old[a] += d;
            old[b] += d;
        }
    }

    let mut ans = nop_turn;
    for i in 1..=n {
        let mut nb = &mut neighbors[i];
        if nb.is_empty() {
            continue;
        }
        nb.sort_unstable();
        let len = nb.len();
        let mut new = 0;
        for i in 0..len / 2 {
            new += nb[len - 1 - i] - nb[i];
        }
        let turn = new - old[i] + nop_turn;
        ans = ans.min(turn);
    }
    ans
}
