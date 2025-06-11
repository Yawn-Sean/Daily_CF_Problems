//! core logic only
//! submission: https://codeforces.com/problemset/submission/1080/309989826
const MULTIPLE_TEST: bool = false;
const MOD: u64 = 998_244_353;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::hash_map::RandomState;
    use std::hash::{BuildHasher, Hasher};
    let base = RandomState::new().build_hasher().finish() % 1000 + 1000;
    let mut pows = [1; 26];
    pows[1] = base;
    for i in 2..26 {
        pows[i] = (pows[i - 1] * base) % MOD;
    }

    let mat: Vec<_> = scanner.iter(n).map(String::into_bytes).collect();
    let mut ans = 0;
    for s in 0..m {
        let mut hash = vec![0; n];
        let mut mask = vec![0; n];
        for e in s..m {
            let mut l = 0;
            for (r, row) in mat.iter().enumerate() {
                let b = row[e] - b'a';
                hash[r] += pows[b as usize];
                hash[r] %= MOD;
                mask[r] ^= 1u32 << b;
                if mask[r].count_ones() > 1 {
                    ans += manacher(&hash[l..r]);
                    l = r + 1;
                    continue;
                }
            }
            ans += manacher(&hash[l..n]);
        }
    }
    ans
}

fn manacher(xs: &[u64]) -> usize {
    if xs.is_empty() {
        return 0;
    }
    let n = xs.len() * 2 + 1;
    let xs = {
        let mut new_xs = Vec::with_capacity(2 * n + 1);
        new_xs.push(u64::MAX);
        for &x in xs {
            new_xs.push(x);
            new_xs.push(u64::MAX);
        }
        new_xs
    };
    let mut arm = vec![0; n];
    // xs[idx - len     ..= idx + len] is palindrome
    // xs[idx - len - 1 ..= idx + len + 1] is not palindrome
    let mut idx = 0;
    let mut len = 0;
    let mut ans = 0;
    for i in 1..n {
        let mut l = if i <= idx + len {
            arm[2 * idx - i].min(idx + len - i)
        } else {
            0
        };
        while i >= l + 1 && i + l + 1 < n && xs[i + l + 1] == xs[i - l - 1] {
            l += 1;
        }
        ans += (l + 1) / 2;
        arm[i] = l;
        if i + l > idx + len {
            idx = i;
            len = l;
        }
    }
    ans
}
