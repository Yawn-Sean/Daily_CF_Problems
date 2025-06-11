//! core logic only
//! submission: https://codeforces.com/problemset/submission/896/297094214
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, c: usize, scanner: &mut Scanner) -> impl Printable {
    let mut sheets = vec![0; n];
    let mut written = 0;
    for _ in 0..m {
        let x = usize::from_scanner(scanner);
        if x <= c / 2 {
            for (sheet, i) in sheets.iter_mut().zip(1..=n) {
                if *sheet == 0 || *sheet > x {
                    written += usize::from(*sheet == 0);
                    *sheet = x;
                    println!("{}", i);
                    break;
                }
            }
        } else {
            for (i, sheet) in sheets.iter_mut().enumerate().rev() {
                if *sheet == 0 || *sheet < x {
                    written += usize::from(*sheet == 0);
                    *sheet = x;
                    println!("{}", i + 1);
                    break;
                }
            }
        }
        if written == n {
            break;
        }
    }
    ""
}
