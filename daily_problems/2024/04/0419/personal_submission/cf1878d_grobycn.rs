// core logic only
// submission: https://codeforces.com/contest/1878/submission/257287275
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, k: usize, s: String, scanner: &mut Scanner) -> impl Printable {
    let mut s = s.into_bytes();
    let ls: Vec<usize> = scanner.iter(k).collect();
    let rs: Vec<usize> = scanner.iter(k).collect();
    let mut xs = <Vec<usize>>::from_scanner(scanner);
    xs.sort_unstable();

    let mut rev = vec![false; n + 1];
    let mut i = 0;
    for x in xs {
        while rs[i] < x {
            i += 1;
        }
        let y = rs[i] + ls[i] - x;
        let (mn, mx) = if x < y { (x - 1, y) } else { (y - 1, x) };
        rev[mn] ^= true;
        rev[mx] ^= true;
    }

    i = 0;
    let mut reverse = false;
    for x in 1..=n {
        while rs[i] < x {
            i += 1;
        }
        reverse ^= rev[x - 1];
        if reverse {
            let mirror = rs[i] + ls[i] - x;
            if x < mirror {
                s.swap(x - 1, mirror - 1);
            }
        }
    }
    unsafe { String::from_utf8_unchecked(s) }
}
