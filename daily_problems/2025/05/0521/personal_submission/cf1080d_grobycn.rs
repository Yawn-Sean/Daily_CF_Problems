//! core logic only
//! submission: https://codeforces.com/problemset/submission/1080/320660763
const MULTIPLE_TEST: bool = true;

fn solver(n: usize, k: usize) -> impl Printable {
    if n > 31 {
        return Ok(("YES", n - 1));
    }

    let mut ans = n;
    let mut side = 1;
    let mut op_min = 0;
    let mut op_max = 0;
    let mut op_uniform = 0;
    while ans > 0 && op_max < k {
        op_min += 2 * side - 1;
        op_uniform += side * side;
        side <<= 1;
        ans -= 1;
        op_max = op_uniform + (side * side - (2 * side - 1)) * (((1 << (2 * ans)) - 1) / 3);
        if op_min <= k && k <= op_max {
            return Ok(("YES", ans));
        }
    }
    Err("NO")
}
