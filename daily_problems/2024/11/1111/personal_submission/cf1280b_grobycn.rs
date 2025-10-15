//! core logic only
//! submission: https://codeforces.com/contest/1280/submission/291079984
const MULTIPLE_TEST: bool = true;

fn solver(r: usize, c: usize, scanner: &mut Scanner) -> impl Printable {
    let mut total = 0;
    let mut rcnt = vec![0; r];
    let mut ccnt = vec![0; c];
    let mut has_corner = false;
    for (i, row) in scanner.iter::<String>(r).enumerate() {
        for (j, b) in row.bytes().enumerate() {
            if b == b'A' {
                total += 1;
                rcnt[i] += 1;
                ccnt[j] += 1;
                if (i == 0 || i == r - 1) && (j == 0 || j == c - 1) {
                    has_corner = true;
                }
            }
        }
    }
    if total == 0 {
        return Err("MORTAL");
    }
    if total == r * c {
        return Ok(0);
    }
    if rcnt[0] == c || rcnt[r - 1] == c || ccnt[0] == r || ccnt[c - 1] == r {
        return Ok(1);
    }
    if rcnt.iter().any(|&cnt| cnt == c) || ccnt.iter().any(|&cnt| cnt == r) {
        return Ok(2);
    }
    if has_corner {
        return Ok(2);
    }
    if rcnt[0] != 0 || rcnt[r - 1] != 0 || ccnt[0] != 0 || ccnt[c - 1] != 0 {
        return Ok(3);
    }
    Ok(4)
}
