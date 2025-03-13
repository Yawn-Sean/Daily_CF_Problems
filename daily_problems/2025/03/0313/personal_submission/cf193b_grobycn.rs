//! core logic only
//! submission: https://codeforces.com/problemset/submission/193/310425762
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, u: usize, r: i64, scanner: &mut Scanner) -> impl Printable {
    let mut a: Vec<i64> = scanner.iter(n).collect();
    let b: Vec<i64> = scanner.iter(n).collect();
    let k: Vec<i64> = scanner.iter(n).collect();
    let p: Vec<usize> = scanner.iter(n).collect();

    fn brute_force(
        a: &mut [i64],
        b: &[i64],
        k: &[i64],
        p: &[usize],
        u: usize,
        r: i64,
        xored: bool,
        ans: &mut i64,
    ) {
        if u % 2 == 0 {
            // xor b twice result in original a
            let s = a.iter().zip(k).map(|(&ai, &ki)| ai * ki).sum::<i64>();
            *ans = s.max(*ans);
        }
        if u == 0 {
            return;
        }
        if !xored {
            a.iter_mut().zip(b).for_each(|(ai, &bi)| *ai ^= bi);
            brute_force(a, b, k, p, u - 1, r, true, ans);
            a.iter_mut().zip(b).for_each(|(ai, &bi)| *ai ^= bi);
        }
        let bak = a.to_vec();
        a.iter_mut()
            .zip(p)
            .for_each(|(ai, &pi)| *ai = bak[pi - 1] + r);
        brute_force(a, b, k, p, u - 1, r, false, ans);
        a.iter_mut().zip(bak).for_each(|(ai, x)| *ai = x);
    }

    let mut ans = i64::MIN;
    brute_force(&mut a, &b, &k, &p, u, r, false, &mut ans);
    ans
}
