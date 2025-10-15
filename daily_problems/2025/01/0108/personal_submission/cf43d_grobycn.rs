//! core logic only
//! submission: https://codeforces.com/problemset/submission/43/300169520
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize) -> impl Printable {
    let mut k = 0;
    let mut ans = vec![];
    match (n, m) {
        (1, _) => {
            k = usize::from(m != 2);
            ans.extend((1..=m).map(|c| (1, c)).chain([(1, 1)]));
        }
        (_, 1) => {
            k = usize::from(n != 2);
            ans.extend((1..=n).map(|r| (r, 1)).chain([(1, 1)]));
        }
        (n, _) if n & 1 == 0 => {
            ans.extend((1..=n).map(|r| (r, 1)));
            for r in (1..=n).rev() {
                if r & 1 == 0 {
                    ans.extend((2..=m).map(|c| (r, c)));
                } else {
                    ans.extend((2..=m).map(|c| (r, c)).rev());
                }
            }
            ans.push((1, 1));
        }
        (_, m) if m & 1 == 0 => {
            ans.extend((1..=m).map(|c| (1, c)));
            for c in (1..=m).rev() {
                if c & 1 == 0 {
                    ans.extend((2..=n).map(|r| (r, c)));
                } else {
                    ans.extend((2..=n).map(|r| (r, c)).rev());
                }
            }
            ans.push((1, 1));
        }
        _ => {
            k = 1;
            for r in 1..=n {
                if r & 1 == 0 {
                    ans.extend((1..=m).map(|c| (r, c)).rev());
                } else {
                    ans.extend((1..=m).map(|c| (r, c)));
                }
            }
            ans.push((1, 1));
        }
    }
    let porter = if k == 0 {
        Ok(0)
    } else {
        Err(1.cr().then((n, m, 1, 1)))
    };
    porter.cr().then(Sep::<_, '\n'>(ans))
}
