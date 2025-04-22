//! core logic only
//! submission: https://codeforces.com/problemset/submission/490/316697459
const MULTIPLE_TEST: bool = false;

fn solver(a1: usize, b1: usize, a2: usize, b2: usize) -> impl Printable {
    fn count_factor_2_3(mut x: usize) -> (u32, u32, usize) {
        let cnt2 = x.trailing_zeros();
        x >>= cnt2;
        let mut cnt3 = 0;
        while x % 3 == 0 {
            cnt3 += 1;
            x /= 3;
        }
        (cnt2, cnt3, x)
    }

    let (mut cnt2a1, mut cnt3a1, mut a1) = count_factor_2_3(a1);
    let (mut cnt2b1, mut cnt3b1, mut b1) = count_factor_2_3(b1);
    let (mut cnt2a2, mut cnt3a2, mut a2) = count_factor_2_3(a2);
    let (mut cnt2b2, mut cnt3b2, mut b2) = count_factor_2_3(b2);

    if a1 * b1 != a2 * b2 {
        return Err(-1);
    }

    let mut minutes = 0;
    let cnt3 = (cnt3a1 + cnt3b1).min(cnt3a2 + cnt3b2);
    while cnt3a1 + cnt3b1 > cnt3 {
        minutes += 1;
        if cnt3a1 > 0 {
            cnt3a1 -= 1;
            cnt2a1 += 1;
        } else {
            cnt3b1 -= 1;
            cnt2b1 += 1;
        }
    }
    while cnt3a2 + cnt3b2 > cnt3 {
        minutes += 1;
        if cnt3a2 > 0 {
            cnt3a2 -= 1;
            cnt2a2 += 1;
        } else {
            cnt3b2 -= 1;
            cnt2b2 += 1;
        }
    }

    let cnt2 = (cnt2a1 + cnt2b1).min(cnt2a2 + cnt2b2);
    while cnt2a1 + cnt2b1 > cnt2 {
        minutes += 1;
        if cnt2a1 > 0 {
            cnt2a1 -= 1;
        } else {
            cnt2b1 -= 1;
        }
    }
    while cnt2a2 + cnt2b2 > cnt2 {
        minutes += 1;
        if cnt2a2 > 0 {
            cnt2a2 -= 1;
        } else {
            cnt2b2 -= 1;
        }
    }

    a1 = a1 * (1usize << cnt2a1) * (3usize.pow(cnt3a1));
    b1 = b1 * (1usize << cnt2b1) * (3usize.pow(cnt3b1));
    a2 = a2 * (1usize << cnt2a2) * (3usize.pow(cnt3a2));
    b2 = b2 * (1usize << cnt2b2) * (3usize.pow(cnt3b2));
    Ok(minutes.cr().then((a1, b1)).cr().then((a2, b2)))
}
