//! core logic only
//! submission: https://codeforces.com/problemset/submission/1090/313623186
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashMap;
    let mut group = HashMap::new();
    for ((s, t), i) in scanner.iter::<(String, String)>(n).zip(1..) {
        let mask = t.bytes().fold(0u32, |acc, b| acc | (1 << (b - b'a')));
        let cnt = s
            .bytes()
            .rev()
            .take_while(|b| mask & (1 << (b - b'a')) != 0)
            .count();
        let prefix = String::from(&s[..s.len() - cnt]);
        group.entry((prefix, mask)).or_insert(vec![]).push(i);
    }
    group.len().cr().then(Sep::<_, '\n'>(
        group.into_values().map(|g| (g.len(), Sep::<_, ' '>(g))),
    ))
}
