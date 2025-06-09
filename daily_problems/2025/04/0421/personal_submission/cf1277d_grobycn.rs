//! core logic only
//! submission: https://codeforces.com/contest/1277/submission/316519049
const MULTIPLE_TEST: bool = true;

fn solver(words: Vec<String>) -> impl Printable {
    use std::collections::HashSet;
    let set: HashSet<_> = words.iter().collect();
    let (mut w00, mut w01, mut w10, mut w11) = (vec![], vec![], vec![], vec![]);
    for (i, w) in words.iter().enumerate() {
        let w = w.as_bytes();
        match (w[0], w[w.len() - 1]) {
            (b'0', b'0') => w00.push(i),
            (b'0', b'1') => w01.push(i),
            (b'1', b'0') => w10.push(i),
            (b'1', b'1') => w11.push(i),
            _ => unreachable!(),
        }
    }

    if w01.is_empty() && w10.is_empty() && !w00.is_empty() && !w11.is_empty() {
        return Err(-1);
    }

    let mut ans = vec![];
    let (mut c01, mut c10) = (w01.len(), w10.len());
    if c01 < c10 {
        std::mem::swap(&mut c01, &mut c10);
        std::mem::swap(&mut w01, &mut w10);
    }
    while c01 > c10 + 1 {
        let i = w01.pop().unwrap();
        let mut rev = words[i].as_bytes().to_vec();
        rev.reverse();
        let rev = unsafe { String::from_utf8_unchecked(rev) };
        if set.contains(&rev) {
            continue;
        }
        ans.push(i + 1);
        c01 -= 2;
    }

    Ok(ans.len().cr().then(Sep::<_, ' '>(ans)))
}
