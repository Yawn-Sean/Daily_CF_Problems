// core logic only
// submission: https://codeforces.com/contest/819/submission/266955571
const MULTIPLE_TEST: bool = false;

fn solver(p: Vec<usize>) -> impl Printable {
    use std::iter::repeat;
    let n = p.len();
    let mut gt: VecDeque<_> = repeat(0).take(n - 1).collect();
    let mut gtsum = 0;
    let mut le: VecDeque<_> = repeat(0).take(n).collect();
    let mut lesum = 0;
    let mut deviation = 0;
    for (&x, i) in p.iter().zip(1..) {
        if x > i {
            gt[x - i - 1] += 1;
            gtsum += 1;
            deviation += x - i;
        } else {
            le[i - x] += 1;
            lesum += 1;
            deviation += i - x;
        }
    }

    let (mut id, mut mn) = (0, deviation);
    for k in 1..n {
        let x = p[n - k];
        le[n - x] -= 1;
        lesum -= 1;
        deviation -= n - x;
        deviation = deviation + lesum - gtsum;
        if let Some(c) = gt.pop_front() {
            gtsum -= c;
            lesum += c;
            le.push_front(c);
        }
        if let Some(c) = le.pop_back() {
            lesum -= c;
            gtsum += c;
            gt.push_back(c);
        }
        if x == 1 {
            le[0] += 1;
            lesum += 1;
        } else {
            gt[x - 2] += 1;
            gtsum += 1;
        }
        deviation += x - 1;
        if deviation < mn {
            mn = deviation;
            id = k;
        }
    }

    (mn, id)
}
