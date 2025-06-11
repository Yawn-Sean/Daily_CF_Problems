//! core logic only
//! submission: https://codeforces.com/problemset/submission/1157/302610865
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    const MAXA: usize = 200_000;
    let mut count = vec![0; MAXA + 2];
    for x in scanner.iter::<usize>(n) {
        count[x] += 1;
    }

    let mut mx = 0;
    let (mut lo, mut hi) = (0, 0);
    let mut i = 1;
    while i <= MAXA {
        if count[i] != 0 {
            let mut sum = count[i];
            let mut e = i + 1;
            while e <= MAXA && count[e] > 1 {
                sum += count[e];
                e += 1;
            }
            sum += count[e];
            if sum > mx {
                mx = sum;
                (lo, hi) = (i, e);
            }
            i = e;
        } else {
            i += 1;
        }
    }
    if count[hi] == 0 {
        hi -= 1;
    }
    let mut circle = Vec::with_capacity(mx);
    for h in lo..=hi {
        count[h] -= 1;
        circle.push(h);
    }
    for h in (lo..=hi).rev() {
        circle.extend(std::iter::repeat(h).take(count[h]));
    }
    mx.cr().then(Sep::<_, ' '>(circle))
}
