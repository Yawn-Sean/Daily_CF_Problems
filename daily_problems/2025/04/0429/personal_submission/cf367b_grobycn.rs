//! core logic only
//! submission: https://codeforces.com/problemset/submission/367/317746431
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, p: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::HashMap;

    fn add_one(set: &mut HashMap<u32, usize>, x: u32) {
        *set.entry(x).or_default() += 1;
    }
    fn remove_one(set: &mut HashMap<u32, usize>, x: &u32) {
        match set.get_mut(x) {
            Some(cnt) if *cnt > 1 => *cnt -= 1,
            Some(_) => {
                set.remove(x);
            }
            None => {}
        }
    }

    let a: Vec<u32> = scanner.iter(n).collect();
    let mut b = HashMap::new();
    scanner.iter::<u32>(m).for_each(|x| add_one(&mut b, x));
    let mut ans = vec![];

    for q in 0..p {
        if q + (m - 1) * p >= n {
            break;
        }
        let mut set = HashMap::new();
        let mut len = 0;
        let mut eq_cnt = 0;
        for i in (q..n).step_by(p) {
            let x = a[i];
            add_one(&mut set, x);
            len += 1;
            let cntx = set[&x];
            let cntx_want = *b.get(&x).unwrap_or(&0);
            if cntx == cntx_want {
                eq_cnt += 1;
            } else if cntx == cntx_want + 1 {
                eq_cnt -= 1;
            }
            if len > m {
                let x = a[i - m * p];
                let cntx = set[&x];
                remove_one(&mut set, &x);
                let cntx_want = *b.get(&x).unwrap_or(&0);
                if cntx == cntx_want {
                    eq_cnt -= 1;
                } else if cntx == cntx_want + 1 {
                    eq_cnt += 1;
                }
                len -= 1;
            }
            if len == m && eq_cnt == b.len() {
                ans.push(i + 1 - (m - 1) * p);
            }
        }
    }

    ans.sort_unstable();
    ans.len().cr().then(Sep::<_, ' '>(ans))
}
