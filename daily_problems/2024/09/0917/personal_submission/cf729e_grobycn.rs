//! core logic only
//! submission: https://codeforces.com/problemset/submission/729/281608996
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, s: usize, scanner: &mut Scanner) -> impl Printable {
    let mut count = vec![0; n];
    let mut ans = 0;
    for (i, ai) in scanner.iter::<usize>(n).enumerate() {
        if i == s - 1 {
            ans += usize::from(ai != 0);
        } else {
            count[ai] += 1;
        }
    }
    if n == 1 {
        return ans;
    }

    let mut last = n - 1;
    while count[last] == 0 {
        last -= 1;
    }
    let mut i = 1;
    while i < last {
        if count[i] == 0 {
            count[i] = 1;
            if count[0] > 0 {
                count[0] -= 1;
            } else {
                count[last] -= 1;
                while count[last] == 0 {
                    last -= 1;
                }
            }
            ans += 1;
        }
        i += 1;
    }
    ans + count[0]
}
