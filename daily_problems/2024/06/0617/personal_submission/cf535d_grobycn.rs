// core logic only
// submission: https://codeforces.com/contest/535/submission/266201313
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, m: usize, p: String, scanner: &mut Scanner) -> impl Printable {
    let len = p.len();
    let pb = p.as_bytes();
    let mut z = vec![0; len];
    let mut l = 0;
    for i in 1..len {
        let mut d = if i <= l + z[l] {
            z[i - l].min(l + z[l] - i)
        } else {
            0
        };
        while i + d < len && pb[d] == pb[i + d] {
            d += 1;
        }
        z[i] = d;
        if z[i] + i > z[l] + l {
            l = i;
        }
    }

    let mut s = vec![0; n];
    let mut r = 0;
    for mut y in scanner.iter::<usize>(m) {
        y -= 1;
        if y >= r {
            for (b, i) in p.bytes().zip(y..) {
                s[i] = b;
            }
        } else {
            if z[len - (r - y)] != r - y {
                return 0;
            }
            let p = &p[r - y..];
            for (b, i) in p.bytes().zip(r..) {
                s[i] = b;
            }
        }
        r = y + len;
    }

    let mut cnt = s.iter().filter(|&&b| b == 0).count();
    let mut ans = 1;
    let mut base = 26;
    while cnt > 0 {
        if cnt & 1 != 0 {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        cnt >>= 1;
    }
    ans
}
