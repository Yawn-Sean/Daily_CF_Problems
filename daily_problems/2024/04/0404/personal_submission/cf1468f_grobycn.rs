// core logic only
// submission: https://codeforces.com/problemset/submission/1468/255484569
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut count = std::collections::HashMap::new();
    let mut ans = 0usize;

    for (x, y, u, v) in scanner.iter::<(i32, i32, i32, i32)>(n) {
        let mut dx = u - x;
        let mut dy = v - y;
        let g = gcd(dx.abs(), dy.abs());
        dx /= g;
        dy /= g;
        ans += *count.get(&(-dx, -dy)).unwrap_or(&0);
        *count.entry((dx, dy)).or_insert(0) += 1;
    }

    ans
}

fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let t = b;
        b = a % b;
        a = t;
    }
    a
}
