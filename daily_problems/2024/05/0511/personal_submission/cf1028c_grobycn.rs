// core logic only
// submission: https://codeforces.com/problemset/submission/1028/260542554
const MULTIPLE_TEST: bool = false;

fn solver(rect: Vec<(i32, i32, i32, i32)>) -> impl Printable {
    let n = rect.len();
    let (mut xmin, mut ymin, mut xmax, mut ymax) = (i32::MIN, i32::MIN, i32::MAX, i32::MAX);
    let mut left = Vec::with_capacity(n + 1);
    left.push((xmin, ymin, xmax, ymax));
    for &(blx, bly, urx, ury) in &rect {
        xmin = xmin.max(blx);
        ymin = ymin.max(bly);
        xmax = xmax.min(urx);
        ymax = ymax.min(ury);
        left.push((xmin, ymin, xmax, ymax));
    }
    (xmin, ymin, xmax, ymax) = (i32::MIN, i32::MIN, i32::MAX, i32::MAX);
    for (&(blx, bly, urx, ury), &(xminl, yminl, xmaxl, ymaxl)) in rect.iter().zip(&left).rev() {
        let xmn = xmin.max(xminl);
        let ymn = ymin.max(yminl);
        let xmx = xmax.min(xmaxl);
        let ymx = ymax.min(ymaxl);
        if xmn <= xmx && ymn <= ymx {
            return (xmn, ymn);
        }
        xmin = xmin.max(blx);
        ymin = ymin.max(bly);
        xmax = xmax.min(urx);
        ymax = ymax.min(ury);
    }
    unreachable!()
}
