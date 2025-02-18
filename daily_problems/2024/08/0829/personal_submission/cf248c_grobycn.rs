//! core logic only
//! submission: https://codeforces.com/problemset/submission/248/278657915
const MULTIPLE_TEST: bool = false;

fn solver(y1: i128, y2: i128, yw: i128, xb: i128, yb: i128, r: i128) -> impl Printable {
    let (y1m, y2m) = (2 * (yw - r) - y1, 2 * (yw - r) - y2);
    let dy = y1m - r - yb;
    if ((y1m - r - y2m) * xb) * ((y1m - r - y2m) * xb) < r * r * (xb * xb + dy * dy) {
        return Err(-1);
    }
    Ok(((xb * dy - (yw - r - yb) * xb) as f64) / (dy as f64))
}
