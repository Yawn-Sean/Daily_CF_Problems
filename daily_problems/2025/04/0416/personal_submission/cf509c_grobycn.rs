//! core logic only
//! submission: https://codeforces.com/problemset/submission/509/315846521
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    fn digits2string(digits: &[usize]) -> String {
        unsafe {
            String::from_utf8_unchecked(
                digits
                    .iter()
                    .skip_while(|&d| *d == 0)
                    .map(|&x| (x as u8) + b'0')
                    .collect(),
            )
        }
    }

    let mut ans = Vec::with_capacity(n);
    let mut limit = [0; 350];
    let mut limit_digits_sum = 0;
    for b in scanner.iter::<usize>(n) {
        'outer: for i in (0..350).rev() {
            for d in limit[i] + 1..10 {
                let min = limit_digits_sum + d - limit[i];
                let max = min + (349 - i) * 9;
                if min <= b && b <= max {
                    limit[i] = d;
                    let mut rest = b - min;
                    for j in (i + 1..350).rev() {
                        let d = rest.min(9);
                        limit[j] = d;
                        rest -= d;
                    }
                    break 'outer;
                }
            }
            limit_digits_sum -= limit[i];
        }
        limit_digits_sum = b;
        ans.push(digits2string(&limit));
    }
    Sep::<_, '\n'>(ans)
}
