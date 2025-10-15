//! core logic only
//! submission: https://codeforces.com/problemset/submission/848/311281882
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, w: i32, h: i32, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashMap;
    let mut groups = HashMap::new();
    for (i, (g, p, t)) in scanner.iter::<(u8, i32, i32)>(n).enumerate() {
        let e = groups.entry(t - p).or_insert(vec![]);
        if g == 1 {
            e.push((p, i));
        } else {
            e.push((-p, i));
        }
    }

    let mut ans = vec![(0, 0); n];
    for g in groups.values_mut() {
        let mut dest: Vec<_> = g
            .iter()
            .map(|&(p, _)| if p > 0 { (p, h) } else { (w, -p) })
            .collect();
        dest.sort_unstable_by_key(|&(x, y)| x - y);
        g.sort_unstable_by_key(|&(p, _)| p);
        g.iter().zip(dest).for_each(|(&(_, i), d)| ans[i] = d);
    }
    Sep::<_, '\n'>(ans)
}
