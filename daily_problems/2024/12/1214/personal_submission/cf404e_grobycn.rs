//! core logic only
//! submission: https://codeforces.com/problemset/submission/404/296370856
const MULTIPLE_TEST: bool = false;

fn solver(s: String) -> impl Printable {
    let d = if s.ends_with("L") { 1 } else { -1 };
    let check = |ob: i32| {
        let mut x = 0;
        let mut mn = 0;
        let mut mncnt = 1;
        for b in s.bytes() {
            if b == b'L' {
                x -= d;
            } else {
                x += d;
            }
            if x == ob {
                x = ob - 1;
            }
            if x < mn {
                mn = x;
                mncnt = 1;
            } else if x == mn {
                mncnt += 1;
            }
        }
        x == mn && mncnt == 1
    };

    if check(1_000_000) {
        return 1;
    }
    let (mut lo, mut hi) = (1, 1_000_000);
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        if check(mid) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    hi - 1
}
