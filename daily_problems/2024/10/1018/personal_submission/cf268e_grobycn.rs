//! core logic only
//! submission: https://codeforces.com/problemset/submission/268/286548613
const MULTIPLE_TEST: bool = false;

fn solver(mut songs: Vec<(usize, usize)>) -> impl Printable {
    songs.sort_unstable_by(|&(l1, p1), &(l2, p2)| {
        let exp12 = l1 * p1 * (100 - p2);
        let exp21 = l2 * p2 * (100 - p1);
        exp21.cmp(&exp12)
    });

    let mut ans = 0;
    let mut acc = 0;
    for (l, p) in songs {
        ans += l * 10000 + acc * (100 - p);
        acc += l * p;
    }

    (ans as f64) / 10000.0
}
