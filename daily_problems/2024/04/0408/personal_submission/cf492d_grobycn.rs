// core logic only
// submission: https://codeforces.com/problemset/submission/492/255622029
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, x: usize, y: usize, scanner: &mut Scanner) -> impl Printable {
    let z = x.min(y);
    let ans: Vec<_> = scanner
        .iter(n)
        .map(|ai: usize| {
            let (mut lo, mut hi) = (0, z * ai);
            while lo < hi {
                let mid = (hi - lo) / 2 + lo;
                if mid / x + mid / y >= ai {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            match (hi % x == 0, hi % y == 0) {
                (true, true) => "Both",
                (true, _) => "Vova",
                _ => "Vanya",
            }
        })
        .collect();
    Sep::<_, '\n'>(ans)
}
