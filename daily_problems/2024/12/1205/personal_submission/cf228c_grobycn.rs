//! core logic only
//! submission: https://codeforces.com/problemset/submission/228/294982524
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    const INVALID: u8 = u8::MAX;
    const ALL_BLACK: u8 = 0b1111;

    let field: Vec<_> = scanner.iter(n).map(|s: String| s.into_bytes()).collect();
    let mut pat = vec![vec![0; m - 1]; n - 1];
    for r in 0..n - 1 {
        for c in 0..m - 1 {
            let mut p = 0;
            for dr in 0..2 {
                for dc in 0..2 {
                    p = (p << 1) | u8::from(field[r + dr][c + dc] == b'*');
                }
            }
            pat[r][c] = p;
        }
    }

    let mut ans = 0;
    let mut side = 4;
    while n >= side && m >= side {
        let mut npat = vec![vec![0; m - side + 1]; n - side + 1];
        for r in 0..=n - side {
            for c in 0..=m - side {
                let mut p = 0;
                for dr in 0..2 {
                    for dc in 0..2 {
                        p = (p << 1)
                            | u8::from(pat[r + dr * side / 2][c + dc * side / 2] == ALL_BLACK);
                    }
                }

                let mut flag = true;
                'outer: for dr in 0..2 {
                    for dc in 0..2 {
                        let subp = pat[r + dr * side / 2][c + dc * side / 2];
                        if subp != ALL_BLACK && subp != p {
                            flag = false;
                            break 'outer;
                        }
                    }
                }
                if flag {
                    npat[r][c] = p;
                    ans += 1;
                } else {
                    npat[r][c] = INVALID;
                }
            }
        }
        side <<= 1;
        pat = npat;
    }
    ans
}
