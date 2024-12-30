fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}
fn frac(x1: i64, y1: i64, x2: i64, y2: i64) -> (i64, i64) {
    let a = y2 - y1;
    let b = x2 - x1;
    let g = gcd(a, b);
    if b / g > 0 {
        (a / g, b / g)
    } else {
        (-a / g, -b / g)
    }
}
fn main() {
    input! { n: usize, p: [i64; n] }

    let a1 = frac(0, p[0], 1, p[1]);
    let a2 = frac(0, p[0], 2, p[2]);
    let a3 = frac(1, p[1], 2, p[2]);

    let check = |(a, b): (i64, i64)| {
        let mut r = HashSet::new();
        for i in 0..n {
            let k1 = p[i] * b - i as i64 * a;
            let k2 = b;
            let g = gcd(k1, k2);
            r.insert((k1 / g, k2 / g));
            if r.len() > 2 {
                return false;
            }
        }
        r.len() == 2
    };
    // eprintln!("{:?} {:?} {:?}", a1, a2, a3);

    if check(a1) || check(a2) || check(a3) {
        println!("Yes");
    } else {
        println!("No");
    }
}