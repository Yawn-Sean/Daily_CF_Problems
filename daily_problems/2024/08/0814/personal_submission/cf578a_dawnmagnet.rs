fn main() {
    input! { x: f64, y: f64 }
    if y > x {
        println!("-1")
    } else {
        let j = x - y;
        let k = (j / 2.0 / y).floor();
        let r1 = j / 2.0 / k;
        // println!("{r1}");

        let j = x + y;
        let k = (j / 2.0 / y).floor();
        let r2 = j / 2.0 / k;
        println!("{}", r1.min(r2));
    }
}