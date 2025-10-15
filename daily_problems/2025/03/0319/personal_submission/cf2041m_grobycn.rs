//! core logic only
//! submission: https://codeforces.com/problemset/submission/2041/311421094
const MULTIPLE_TEST: bool = false;

fn solver(mut s: Vec<i32>) -> impl Printable {
    fn solve(xs: &[i32]) -> usize {
        use std::cmp::Reverse;
        use std::collections::binary_heap::PeekMut;
        use std::collections::BinaryHeap;

        let n = xs.len();
        let mut sorted = xs.to_vec();
        sorted.sort_unstable();
        let mut hp: BinaryHeap<Reverse<i32>> = BinaryHeap::new();
        let mut r = 0;
        let mut ans = usize::MAX;
        for (l, &x) in xs.iter().enumerate() {
            while r < l {
                match hp.peek_mut() {
                    Some(top) if top.0 == sorted[r] => {
                        r += 1;
                        PeekMut::pop(top);
                    }
                    _ => break,
                }
            }
            while r >= l && r < n && xs[r] == sorted[r] {
                r += 1;
            }
            if r <= l {
                hp.push(Reverse(x));
            }
            ans = ans.min(l * l + (n - r) * (n - r));
        }
        ans
    }

    let mut ans = solve(&s);
    s.reverse();
    s.iter_mut().for_each(|x| *x *= -1);
    ans.min(solve(&s))
}
