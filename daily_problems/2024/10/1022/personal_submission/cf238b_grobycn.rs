//! core logic only
//! submission: https://codeforces.com/problemset/submission/238/287384970
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, h: usize, scanner: &mut Scanner) -> impl Printable {
    let [mut mn, mut mnat, mut mn2, mut mn3] = [usize::MAX / 2; 4];
    let [mut mx, mut mx2] = [0; 2];
    for (i, x) in scanner.iter::<usize>(n).enumerate() {
        if x <= mn {
            mn3 = mn2;
            mn2 = mn;
            mn = x;
            mnat = i;
        } else if x <= mn2 {
            mn3 = mn2;
            mn2 = x;
        } else if x < mn3 {
            mn3 = x;
        }
        if x >= mx {
            mx2 = mx;
            mx = x;
        } else if x > mx2 {
            mx2 = x;
        }
    }

    let mut ans = vec![1; n];
    let mut goodness = mx + mx2 - mn - mn2;
    let goodness_if_split = (mx + mx2).max(mx + mn + h) - (mn + mn2 + h).min(mn2 + mn3);
    if goodness > goodness_if_split {
        ans[mnat] = 2;
        goodness = goodness_if_split;
    }
    goodness.cr().then(Sep::<_, ' '>(ans))
}
