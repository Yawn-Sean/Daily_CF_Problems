//! core logic only
//! submission: https://codeforces.com/problemset/submission/930/307670202
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let mut count = vec![0; m + 1];
    for (mut l, r) in scanner.iter::<(usize, usize)>(n) {
        l -= 1;
        count[l] += 1;
        count[r] -= 1;
    }
    for i in 1..=m {
        count[i] += count[i - 1];
    }

    let mut lis = vec![];
    let mut left = vec![0; m];
    for (i, &c) in count[..m].iter().enumerate() {
        let p = lis.partition_point(|&x| x <= c);
        if p < lis.len() {
            lis[p] = c;
        } else {
            lis.push(c);
        }
        left[i] = lis.len();
    }

    let mut ans = 0;
    lis.clear();
    for (i, &c) in count[..m].iter().enumerate().rev() {
        ans = ans.max(lis.len() + left[i]);
        let p = lis.partition_point(|&x| x <= c);
        if p < lis.len() {
            lis[p] = c;
        } else {
            lis.push(c);
        }
    }
    ans
}
