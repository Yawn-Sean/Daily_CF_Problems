//! core logic only
//! submission: https://codeforces.com/problemset/submission/753/302747649
const MULTIPLE_TEST: bool = false;

fn solver(scanner: &mut Scanner) -> impl Printable {
    let mut query = |digits: &[u8; 4]| {
        println!("{}{}{}{}", digits[0], digits[1], digits[2], digits[3]);
        let (bulls, cows) = <(u8, u8)>::from_scanner(scanner);
        if bulls == 4 {
            return Ok(());
        }
        Err(bulls + cows)
    };

    let mut digits = [0; 4];
    let mut single = [0; 4];
    for d in digits.iter_mut() {
        while !matches!(query(&single), Err(1)) {
            single.iter_mut().for_each(|d| *d += 1);
        }
        *d = single[0];
        single.iter_mut().for_each(|d| *d += 1);
    }

    while query(&digits).is_err() {
        permutation(&mut digits);
    }

    ""
}

fn permutation(xs: &mut [u8]) {
    let n = xs.len();
    for i in (1..n).rev() {
        if xs[i - 1] < xs[i] {
            let y = xs[i - 1];
            let p = xs[i..n].partition_point(|&x| x > y);
            xs.swap(i - 1, i + p - 1);
            xs[i..n].reverse();
            return;
        }
    }
}
