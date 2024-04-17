// core logic only
// submission: https://codeforces.com/contest/863/submission/257045559
const MULTIPLE_TEST: bool = false;

fn solver(tv: Vec<(usize, usize)>) -> impl Printable {
    let n = tv.len();
    if n == 1 {
        return Err(-1);
    }
    let mut indices: Vec<_> = (0..n).collect();
    indices.sort_unstable_by_key(|&i| tv[i].0);

    let mut prev = indices[0];
    let (mut left, mut right) = tv[indices[0]];
    for &idx in &indices[1..] {
        let (l, r) = tv[idx];
        if r <= right {
            return Ok(idx + 1);
        }
        if l <= left {
            return Ok(prev + 1);
        }
        left = l.max(right + 1);
        right = r;
        prev = idx;
    }

    Err(-1)
}
