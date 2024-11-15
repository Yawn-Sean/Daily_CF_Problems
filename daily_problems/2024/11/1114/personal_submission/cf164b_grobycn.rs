//! core logic only
//! submission: https://codeforces.com/problemset/submission/164/291572706
const MULTIPLE_TEST: bool = false;

fn solver(la: usize, lb: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(la).collect();
    let mut pos = std::collections::HashMap::new();
    for (i, bi) in scanner.iter::<usize>(lb).enumerate() {
        pos.insert(bi, i);
    }
    let mut ans = 0;
    let mut r = 0;
    let mut start_point = 0;
    let mut end_point = 0;
    for (i, ai) in a.iter().enumerate() {
        if pos.contains_key(ai) {
            start_point = pos[ai];
            if r <= i {
                r = i;
                end_point = start_point;
            }

            while r - i < la && pos.contains_key(&a[r % la]) {
                let idx = pos[&a[r % la]];
                if start_point <= end_point {
                    if idx >= end_point {
                        end_point = idx;
                    } else if idx < start_point {
                        end_point = idx;
                    } else {
                        break;
                    }
                } else {
                    if idx > end_point && idx < start_point {
                        end_point = idx;
                    } else {
                        break;
                    }
                }
                r += 1;
            }
            ans = ans.max(r - i);
        }
    }
    ans
}
