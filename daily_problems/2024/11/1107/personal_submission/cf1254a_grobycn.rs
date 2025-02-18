//! core logic only
//! submission: https://codeforces.com/problemset/submission/1254/290401423
const MULTIPLE_TEST: bool = true;

fn solver(r: usize, c: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut grid: Vec<Vec<_>> = scanner.iter::<String>(r).map(|r| r.into_bytes()).collect();
    let cnt = grid
        .iter()
        .map(|r| r.iter())
        .flatten()
        .filter(|&&x| x == b'R')
        .count();
    let avg = cnt / k;
    let mut rem = cnt % k;

    let mut cnt = 0;
    let mut chars = (b'a'..=b'z').chain(b'A'..=b'Z').chain(b'0'..=b'9');
    let mut ch = chars.next().unwrap();
    for (r, row) in grid.iter_mut().enumerate() {
        let cells: Box<dyn Iterator<Item = &mut u8>> = if r & 1 == 0 {
            Box::new(row.iter_mut())
        } else {
            Box::new(row.iter_mut().rev())
        };
        for cell in cells {
            if *cell == b'R' {
                cnt += 1;
                if cnt > avg + usize::from(rem > 0) {
                    cnt = 1;
                    rem = rem.saturating_sub(1);
                    ch = chars.next().unwrap();
                }
            }
            *cell = ch;
        }
    }
    Sep::<_, '\n'>(
        grid.into_iter()
            .map(|r| unsafe { String::from_utf8_unchecked(r) }),
    )
}
