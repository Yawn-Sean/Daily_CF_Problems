//! core logic only
//! submission: https://codeforces.com/problemset/submission/1977/311037182
const MULTIPLE_TEST: bool = true;

fn solver(a: Vec<usize>) -> impl Printable {
    let mx = *a.iter().max().unwrap();
    for &ai in &a {
        if mx % ai != 0 {
            return a.len();
        }
    }

    let special_subseq_with_lcm = |l: usize| {
        let mut real_lcm = 1;
        let mut cnt = 0;
        for &ai in &a {
            if ai == l {
                return None;
            }
            if l % ai == 0 {
                real_lcm = lcm(real_lcm, ai);
                cnt += 1;
            }
        }
        if real_lcm != l {
            None
        } else {
            Some(cnt)
        }
    };

    let mut ans = 0;
    for x in 2.. {
        if x * x > mx {
            break;
        }
        if mx % x == 0 {
            if let Some(cnt) = special_subseq_with_lcm(x) {
                ans = ans.max(cnt);
            }
            if let Some(cnt) = special_subseq_with_lcm(mx / x) {
                ans = ans.max(cnt);
            }
        }
    }
    ans
}

fn gcd(mut a: usize, mut b: usize) -> usize {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}

fn lcm(a: usize, b: usize) -> usize {
    let g = gcd(a, b);
    a / g * b
}
