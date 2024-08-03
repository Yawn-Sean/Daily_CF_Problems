// core logic only
// submission: https://codeforces.com/contest/1903/submission/256126068
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, sx: usize, sy: usize, scanner: &mut Scanner) -> impl Printable {
    let p = (sx ^ sy) & 1;
    let (mut first, mut second) = (vec![], vec![]);
    for ((x, y), i) in scanner.iter::<(usize, usize)>(n).zip(1..) {
        if (x ^ y) & 1 == p {
            second.push(i);
        } else {
            first.push(i);
        }
    }
    let first_win = n / 2 >= first.len();
    if first_win {
        println!("First");
    } else {
        std::mem::swap(&mut first, &mut second);
        println!("Second");
    }

    let mut used = vec![false; n];
    let mut iter = first.iter().chain(&second);
    for i in 0..n {
        if (i % 2 == 0) ^ first_win {
            used[usize::from_scanner(scanner) - 1] = true;
        } else {
            while let Some(&i) = iter.next() {
                if used[i - 1] {
                    continue;
                }
                used[i - 1] = true;
                println!("{i}");
                break;
            }
        }
    }
    ""
}
