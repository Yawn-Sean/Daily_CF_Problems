// core logic only
// submission: https://codeforces.com/problemset/submission/1031/257392913
const MULTIPLE_TEST: bool = false;

fn solver(mut a: usize, mut b: usize) -> impl Printable {
    let mut i = 1;
    let mut day1 = vec![];
    let mut day2 = vec![];
    while i <= a {
        day1.push(i);
        a -= i;
        i += 1;
    }

    if a > 0 {
        let rep = i - a;
        day1[rep - 1] = i;
        if b >= rep {
            day2.push(rep);
            b -= rep;
        }
        i += 1;
    }
    while i <= b {
        day2.push(i);
        b -= i;
        i += 1;
    }

    day1.len()
        .cr()
        .then(Sep::<_, ' '>(day1))
        .cr()
        .then(day2.len())
        .cr()
        .then(Sep::<_, ' '>(day2))
}
