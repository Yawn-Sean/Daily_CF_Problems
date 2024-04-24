// core logic only
// submission: https://codeforces.com/problemset/submission/1912/256782696
const MULTIPLE_TEST: bool = false;

fn solver(mut x: i64, k: usize, scanner: &mut Scanner) -> impl Printable {
    let mut keypoints = vec![];
    for _ in 0..k {
        let n = usize::from_scanner(scanner);
        let (mut mn, mut mx) = (i64::MAX, i64::MIN);
        let mut sum = 0;
        let mut last_mx = 0;
        for x in scanner.iter::<i64>(n) {
            sum += x;
            mn = mn.min(sum);
            mx = mx.max(sum);
            if mx > last_mx {
                keypoints.push((mn, mx - last_mx));
                last_mx = mx;
            }
        }
    }

    keypoints.sort_unstable_by_key(|p| -p.0);
    for (require, delta) in keypoints {
        if x + require >= 0 {
            x += delta;
        }
    }
    x
}
