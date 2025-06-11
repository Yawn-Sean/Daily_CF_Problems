fn main() {
    input! { y1: f64, y2: f64, yw: f64, xb: f64, yb: f64, r: f64 }

    let y1t = (yw - r - y1) + yw - r;
    let y2t = (yw - r - y2) + yw - r;
    let p = y1t - r;
    let k = (yb - p) / (xb);
    let b = p;
    let dis = (y2t - b).abs() / ((1.0 + k * k).sqrt());
    if dis >= r {
        println!("{}", (yw - r - b) / k);
    } else {
        println!("-1");
    }
}