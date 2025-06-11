// core logic only
// submission: https://codeforces.com/problemset/submission/962/262515992
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::cmp::Reverse;
    use std::collections::BinaryHeap;

    let mut ans = vec![];
    let mut hp: BinaryHeap<_> = scanner.iter::<usize>(n).zip(0..n).map(Reverse).collect();
    while let Some(Reverse((x, i))) = hp.pop() {
        match hp.peek_mut() {
            Some(mut top) if top.0 .0 == x => top.0 .0 *= 2,
            _ => ans.push((x, i)),
        }
    }
    ans.sort_unstable_by_key(|p| p.1);
    ans.len()
        .cr()
        .then(Sep::<_, ' '>(ans.into_iter().map(|p| p.0)))
}
