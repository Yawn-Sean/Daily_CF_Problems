//! core logic only
//! submission: https://codeforces.com/problemset/submission/214/311656558
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut count = [0; 10];
    for x in scanner.iter::<usize>(n) {
        count[x] += 1;
    }
    if count[0] == 0 {
        return Err(-1);
    }
    let sum = count.iter().enumerate().map(|(x, &c)| x * c).sum::<usize>();
    let answer = |sum: usize, cnt: &[usize]| {
        if sum == 0 {
            return String::from("0");
        }
        let mut ans = Vec::with_capacity(n);
        for (x, &c) in cnt.iter().enumerate().rev() {
            ans.extend(std::iter::repeat(x as u8 + b'0').take(c));
        }
        unsafe { String::from_utf8_unchecked(ans) }
    };
    if sum % 3 == 0 {
        return Ok(answer(sum, &count));
    }

    for x in 0..10 {
        if count[x] > 0 && (sum - x) % 3 == 0 {
            count[x] -= 1;
            return Ok(answer(sum - x, &count));
        }
    }

    for x in 0..10 {
        if count[x] == 0 {
            continue;
        }
        if count[x] > 1 && (sum - 2 * x) % 3 == 0 {
            count[x] -= 2;
            return Ok(answer(sum - 2 * x, &count));
        }
        for y in x + 1..10 {
            if count[y] > 0 && (sum - x - y) % 3 == 0 {
                count[x] -= 1;
                count[y] -= 1;
                return Ok(answer(sum - x - y, &count));
            }
        }
    }
    unreachable!()
}
