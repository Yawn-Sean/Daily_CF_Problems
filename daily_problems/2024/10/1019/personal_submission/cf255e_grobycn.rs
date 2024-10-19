//! core logic only
//! submission: https://codeforces.com/problemset/submission/255/286635686
const MULTIPLE_TEST: bool = false;

fn solver(mut piles: Vec<usize>) -> impl Printable {
    const MAX_SQRT_A: usize = 881917;

    piles.sort_unstable();
    let mx = MAX_SQRT_A.min(*piles.last().unwrap());
    let mut sg = vec![0; mx + 1];
    let [mut yl, mut yr] = [0; 2];
    let mut count = [0; 5];
    for x in 2..=mx {
        while yr * yr <= x {
            count[sg[yr]] += 1;
            yr += 1;
        }
        while yl.pow(4) < x {
            count[sg[yl]] -= 1;
            yl += 1;
        }
        while count[sg[x]] != 0 {
            sg[x] += 1;
        }
    }

    (yl, yr) = (0, 0);
    let mut ans = 0;
    count = [0; 5];
    for x in piles {
        if x <= mx {
            ans ^= sg[x];
            continue;
        }
        while yr * yr <= x {
            count[sg[yr]] += 1;
            yr += 1;
        }
        while yl.pow(4) < x {
            count[sg[yl]] -= 1;
            yl += 1;
        }
        let mut sg = 0;
        while count[sg] != 0 {
            sg += 1;
        }
        ans ^= sg;
    }
    if ans > 0 {
        "Furlo"
    } else {
        "Rublo"
    }
}
