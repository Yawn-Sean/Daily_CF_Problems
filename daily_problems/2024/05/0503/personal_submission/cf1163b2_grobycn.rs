// core logic only
// submission: https://codeforces.com/contest/1163/submission/259372723
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashMap;

    let mut freq = HashMap::new();
    let mut freq_count = HashMap::new();
    let mut ans = 1;

    for (x, i) in scanner.iter::<u32>(n).zip(1..) {
        let e = freq.entry(x).or_insert(0);
        match freq_count.get_mut(&*e) {
            Some(cnt) if *cnt > 1 => *cnt -= 1,
            _ => {
                freq_count.remove(&*e);
            }
        }
        *e += 1;
        *freq_count.entry(*e).or_insert(0) += 1;
        match freq_count.len() {
            1 => {
                // if all values appear once or all values are same
                if *e == 1 || *e == i {
                    ans = i;
                }
            }
            2 => {
                // if there is one unique value
                if let Some(&1) = freq_count.get(&1) {
                    ans = i;
                } else {
                    let mut ks: Vec<_> = freq_count.keys().copied().collect();
                    let mn = ks[0].min(ks[1]);
                    let mx = ks[0].max(ks[1]);
                    // if there is one value which appears 1 more time than others
                    if mn + 1 == mx && freq_count.get(&mx) == Some(&1) {
                        ans = i;
                    }
                }
            }
            _ => {}
        }
    }

    ans
}
