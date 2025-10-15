//! core logic only
//! submission: https://codeforces.com/problemset/submission/1227/307386355
const MULTIPLE_TEST: bool = false;

fn build_rectangle_count_x(map: &[Vec<u8>]) -> impl Fn(usize, usize, usize, usize) -> usize {
    let (n, m) = (map.len(), map[0].len());
    let mut ps = vec![vec![0; m + 1]; n + 1];
    for (r, row) in map.iter().enumerate() {
        for (c, &b) in row.iter().enumerate() {
            ps[r + 1][c + 1] = ps[r][c + 1] + ps[r + 1][c] - ps[r][c] + usize::from(b == b'X');
        }
    }
    move |tlr: usize, tlc: usize, brr: usize, brc: usize| {
        ps[brr][brc] + ps[tlr][tlc] - ps[tlr][brc] - ps[brr][tlc]
    }
}

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let map: Vec<_> = scanner.iter(n).map(String::into_bytes).collect();
    let countx = build_rectangle_count_x(&map);

    let mut check = |t: usize| {
        let affected_area = (2 * t + 1) * (2 * t + 1);
        let mut setup = vec![vec![b'.'; m]; n];
        for r in 0..n {
            for c in 0..m {
                let tlr = r.saturating_sub(t);
                let tlc = c.saturating_sub(t);
                let blr = (r + t + 1).min(n);
                let blc = (c + t + 1).min(m);
                if countx(tlr, tlc, blr, blc) == affected_area {
                    setup[r][c] = b'X';
                }
            }
        }
        let cntx = build_rectangle_count_x(&setup);
        for (r, row) in map.iter().enumerate() {
            for (c, &b) in row.iter().enumerate() {
                if b == b'X' {
                    let tlr = r.saturating_sub(t);
                    let tlc = c.saturating_sub(t);
                    let blr = (r + t + 1).min(n);
                    let blc = (c + t + 1).min(m);
                    if cntx(tlr, tlc, blr, blc) == 0 {
                        return None;
                    }
                }
            }
        }
        Some(setup)
    };

    let (mut lo, mut hi) = (0, n.min(m) + 1);
    let mut ans = vec![];
    while lo < hi {
        let mid = (hi - lo) / 2 + lo;
        match check(mid) {
            Some(setup) => {
                lo = mid + 1;
                ans = setup;
            }
            None => hi = mid,
        }
    }
    (hi - 1).cr().then(Sep::<_, '\n'>(
        ans.into_iter()
            .map(|row| unsafe { String::from_utf8_unchecked(row) }),
    ))
}
