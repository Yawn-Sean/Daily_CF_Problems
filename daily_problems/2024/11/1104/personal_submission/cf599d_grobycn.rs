//! core logic only
//! submission: https://codeforces.com/problemset/submission/599/289936345
const MULTIPLE_TEST: bool = false;

fn solver(x: usize) -> impl Printable {
    let mut part1 = vec![];
    let mut part2 = vec![];

    for n in 1.. {
        let s = n * (n + 1) * (2 * n + 1) / 6;
        if s > x {
            break;
        }
        let r = x - s;
        let s = n * (n + 1) / 2;
        if r % s != 0 {
            continue;
        }
        let m = r / s + n;
        part1.push((n, m));
        if n != m {
            part2.push((m, n));
        }
    }

    (part1.len() + part2.len()).cr().then(Sep::<_, '\n'>(
        part1.into_iter().chain(part2.into_iter().rev()),
    ))
}
