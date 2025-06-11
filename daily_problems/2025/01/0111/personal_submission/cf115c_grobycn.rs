//! core logic
//! submission: https://codeforces.com/problemset/submission/115/300529618
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    const MOD: usize = 1_000_003;
    let g: Vec<_> = scanner.iter::<String>(n).map(|s| s.into_bytes()).collect();
    let mut empty_lines = 0;
    let isleft = |b: u8| b == b'1' || b == b'2';
    let isupper = |b: u8| b == b'1' || b == b'4';
    for row in g.iter() {
        let mut dot = 0;
        let mut state = None;
        for (c, &b) in row.iter().enumerate() {
            if b == b'.' {
                dot += 1;
            } else {
                let st = (c & 1 == 0) ^ isleft(b);
                match state.as_ref() {
                    Some(&s) if s != st => return 0,
                    None => state = Some(st),
                    _ => {}
                }
            }
        }
        if dot == m {
            empty_lines += 1;
        }
    }

    for c in 0..m {
        let mut dot = 0;
        let mut state = None;
        for (r, row) in g.iter().enumerate() {
            if row[c] == b'.' {
                dot += 1;
            } else {
                let st = (r & 1 == 0) ^ isupper(row[c]);
                match state.as_ref() {
                    Some(&s) if s != st => return 0,
                    None => state = Some(st),
                    _ => {}
                }
            }
        }
        if dot == n {
            empty_lines += 1;
        }
    }
    let mut ans = 1;
    let mut pow = 2;
    while empty_lines > 0 {
        if empty_lines & 1 != 0 {
            ans = (ans * pow) % MOD;
        }
        empty_lines >>= 1;
        pow = (pow * pow) % MOD;
    }
    ans
}
