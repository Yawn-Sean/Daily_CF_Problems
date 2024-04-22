// core logic only
// submission: https://codeforces.com/problemset/submission/558/256939666
const MULTIPLE_TEST: bool = false;

fn solver(a: Vec<usize>) -> impl Printable {
    const MAXA: usize = 100_000;
    let n = a.len();
    let mut count = vec![0; MAXA + 1];
    let mut ops = vec![0; MAXA + 1];
    for &x in &a {
        let mut x = x;
        let mut opcnt = 0;
        while x > 0 {
            count[x] += 1;
            ops[x] += opcnt;
            opcnt += 1;
            x /= 2;
        }
    }
    let mut prefix = 0;
    for x in (1..=MAXA).rev() {
        if count[x] == n {
            prefix = x;
            break;
        }
    }

    let mut ans = ops[prefix];
    prefix *= 2;
    while prefix <= MAXA && count[prefix] * 2 > n {
        ans -= count[prefix] * 2 - n;
        prefix *= 2;
    }
    ans
}
