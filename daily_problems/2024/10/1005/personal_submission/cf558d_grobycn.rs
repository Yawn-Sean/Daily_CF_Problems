//! core logic only
//! submission: https://codeforces.com/contest/558/submission/284416258
const MULTIPLE_TEST: bool = false;

fn intersect((l1, r1): (usize, usize), (l2, r2): (usize, usize)) -> Option<(usize, usize)> {
    let (l, r) = (l1.max(l2), r1.min(r2));
    if l >= r {
        return None;
    }
    Some((l, r))
}

fn solver(h: usize, q: usize, scanner: &mut Scanner) -> impl Printable {
    const CHEAT: &str = "Game cheated!";
    const INSUFFICIENT: &str = "Data not sufficient!";

    let mut range = (1 << (h - 1), 1 << h);
    let mut exclude = vec![];
    for (i, l, r, ans) in scanner.iter::<(usize, usize, usize, u8)>(q) {
        let d = (h - i);
        let (l, r) = (l << d, (r + 1) << d);
        if ans == 0 {
            exclude.push((l, r));
        } else {
            range = match intersect(range, (l, r)) {
                Some(range) => range,
                _ => return Err(CHEAT),
            };
        }
    }

    let mut banned = exclude
        .into_iter()
        .filter_map(|interval| intersect(range, interval))
        .collect::<Vec<_>>();
    banned.sort_unstable();
    banned.dedup_by(|r, l| {
        if l.1 < r.0 {
            false
        } else {
            l.1 = l.1.max(r.1);
            true
        }
    });
    let (left, right) = range;
    match banned.len() {
        0 => {
            if left + 1 == right {
                Ok(left)
            } else {
                Err(INSUFFICIENT)
            }
        }
        1 => {
            if banned[0] == range {
                Err(CHEAT)
            } else if banned[0] == (left + 1, right) {
                Ok(left)
            } else if banned[0] == (left, right - 1) {
                Ok(right - 1)
            } else {
                Err(INSUFFICIENT)
            }
        }
        2 => {
            let (l1, r1) = banned[0];
            let (l2, r2) = banned[1];
            if l1 == left && r2 == right && r1 + 1 == l2 {
                Ok(r1)
            } else {
                Err(INSUFFICIENT)
            }
        }
        _ => Err(INSUFFICIENT),
    }
}
