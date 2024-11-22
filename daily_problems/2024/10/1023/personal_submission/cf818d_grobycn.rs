//! core logic only
//! submission: https://codeforces.com/problemset/submission/818/287523894
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, a: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashMap;
    let mut indices = HashMap::new();
    for (i, ci) in scanner.iter::<usize>(n).enumerate() {
        indices.entry(ci).or_insert(vec![]).push(i);
    }
    match indices.get(&a) {
        None => Ok(1_000_001 - a),
        Some(idxa) => {
            for (&b, idxb) in indices.iter() {
                if b != a && idxb.len() >= idxa.len() {
                    if idxa.iter().zip(idxb).all(|(a, b)| a > b) {
                        return Ok(b);
                    }
                }
            }
            Err(-1)
        }
    }
}
