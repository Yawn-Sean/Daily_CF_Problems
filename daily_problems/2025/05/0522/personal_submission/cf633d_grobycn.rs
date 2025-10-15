//! core logic only
//! submission: https://codeforces.com/problemset/submission/633/320786870
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<i32>) -> impl Printable {
    use std::collections::HashMap;
    let mut count = HashMap::new();
    for &ai in &a {
        *count.entry(ai).or_insert(0) += 1;
    }

    let mut ans = 2;
    if let Some(&c) = count.get(&0) {
        ans = ans.max(c);
    }

    for (i, &f0) in a.iter().enumerate() {
        for (j, &f1) in a.iter().enumerate() {
            if i == j || (f0, f1) == (0, 0) {
                continue;
            }
            let mut seq = vec![f0, f1];
            *count.entry(f0).or_insert(0) -= 1;
            *count.entry(f1).or_insert(0) -= 1;
            let (mut f0, mut f1) = (f0, f1);
            while let Some(c) = count.get_mut(&(f0 + f1)) {
                if *c > 0 {
                    *c -= 1;
                    seq.push(f0 + f1);
                    (f1, f0) = (f1 + f0, f1);
                } else {
                    break;
                }
            }
            ans = ans.max(seq.len());
            seq.iter().for_each(|&x| *count.entry(x).or_insert(0) += 1);
        }
    }
    ans
}
