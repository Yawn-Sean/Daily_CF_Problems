//! core logic only
//! submission: https://codeforces.com/problemset/submission/1063/281475705
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut ask = |x: usize| {
        println!("{x} 1");
        String::from_scanner(scanner) == "black"
    };

    let isblack0 = ask(0);
    let mut cur = 0;
    let mut same_as_left = true;
    for shift in (0..=28).rev().take(n - 1) {
        if same_as_left {
            cur += 1 << shift;
        } else {
            cur -= 1 << shift;
        }
        same_as_left = ask(cur) == isblack0;
    }
    if same_as_left {
        (cur, 0, cur + 1, 2)
    } else {
        (cur - 1, 0, cur, 2)
    }
}
