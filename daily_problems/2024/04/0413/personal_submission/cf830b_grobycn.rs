// core logic only
// submission: https://codeforces.com/contest/830/submission/256592940
const MULTIPLE_TEST: bool = false;

fn solver(cards: Vec<i32>) -> impl Printable {
    let n = cards.len();
    let mut indices: Vec<_> = (0..n).collect();
    // stable sort
    indices.sort_by_key(|&i| cards[i]);
    let mut ans = n;
    let mut rmax = 0;
    let mut i = 0;
    while i < n {
        let mut e = i + 1;
        while e < n && cards[indices[e]] == cards[indices[i]] {
            e += 1;
        }
        let mut new_rmax = 0;
        let indices = &indices[i..e];
        let m = indices.len();
        let p = indices.partition_point(|&idx| idx < rmax);
        if p == 0 {
            rmax = indices[m - 1];
        } else {
            rmax = indices[p - 1];
            ans += n - (m - p + i);
        }
        i = e;
    }
    ans
}
