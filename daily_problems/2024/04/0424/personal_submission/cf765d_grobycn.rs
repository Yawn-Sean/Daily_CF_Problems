// core logic only
// submission: https://codeforces.com/contest/765/submission/257979353
const MULTIPLE_TEST: bool = false;

fn solver(f: Vec<usize>) -> impl Printable {
    let n = f.len();
    let mut h = vec![];
    let mut mapping = vec![usize::MAX; n];
    for (&fi, i) in f.iter().zip(1..) {
        if f[fi - 1] != fi {
            return Err(-1);
        }
        if i == fi {
            h.push(i);
            mapping[fi - 1] = h.len();
        }
    }

    let g = f.into_iter().map(move |fi| mapping[fi - 1]);
    Ok(h.len()
        .cr()
        .then(Sep::<_, ' '>(g))
        .cr()
        .then(Sep::<_, ' '>(h)))
}
