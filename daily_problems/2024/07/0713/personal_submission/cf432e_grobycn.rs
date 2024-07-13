// core logic only
// submission: https://codeforces.com/problemset/submission/432/270344970
const MULTIPLE_TEST: bool = false;

fn border(tlr: usize, tlc: usize, len: usize) -> impl Iterator<Item = (usize, usize)> {
    let (brr, brc) = (tlr + len - 1, tlc + len - 1);
    let right = (tlr..).take(len).map(move |r| (r, brc));
    let bottom = (tlc..).take(len - 1).map(move |c| (brr, c));
    right.chain(bottom)
}

fn check_border(table: &[Vec<u8>], tlr: usize, tlc: usize, len: usize, byte: u8) -> bool {
    border(tlr, tlc, len).all(|(r, c)| table[r][c] == 0 || table[r][c] == byte)
}

fn fill_border(table: &mut [Vec<u8>], tlr: usize, tlc: usize, len: usize, byte: u8) {
    border(tlr, tlc, len).for_each(|(r, c)| table[r][c] = byte)
}

fn check4(table: &[Vec<u8>], r: usize, c: usize, b: u8) -> bool {
    let (n, m) = (table.len(), table[0].len());
    for (i, j) in [
        (r.wrapping_sub(1), c),
        (r + 1, c),
        (r, c.wrapping_sub(1)),
        (r, c + 1),
    ] {
        if i < n && j < m && table[i][j] == b {
            return false;
        }
    }
    true
}

fn check3(table: &[Vec<u8>], r: usize, c: usize, b: u8) -> bool {
    let (n, m) = (table.len(), table[0].len());
    for (i, j) in [(r.wrapping_sub(1), c), (r + 1, c), (r, c + 1)] {
        if i < n && j < m && table[i][j] == b {
            return false;
        }
    }
    true
}

fn solver(n: usize, m: usize) -> impl Printable {
    let mut table = vec![vec![0; m]; n];

    for r in 0..n {
        for c in 0..m {
            if table[r][c] != 0 {
                continue;
            }
            for b in b'A'..=b'Z' {
                if check4(&table, r, c, b) {
                    table[r][c] = b;
                    break;
                }
                if !check3(&table, r, c, b) {
                    continue;
                }
                let mut len = 2;
                while c >= len && table[r][c - len] == b {
                    len += 1;
                }
                if r + len > n {
                    continue;
                }
                if check_border(&table, r, c + 1 - len, len, b) {
                    fill_border(&mut table, r, c + 1 - len, len, b);
                    break;
                }
            }
        }
    }

    Sep::<_, '\n'>(
        table
            .into_iter()
            .map(|row| unsafe { String::from_utf8_unchecked(row) }),
    )
}
