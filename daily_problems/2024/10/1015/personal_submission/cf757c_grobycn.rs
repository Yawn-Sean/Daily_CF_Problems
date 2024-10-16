//! core logic only
//! submission: https://codeforces.com/problemset/submission/757/286075506
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: u32, m: usize, scanner: &mut Scanner) -> impl Printable {
    use std::collections::{hash_map::RandomState, HashMap};
    use std::hash::{BuildHasher, Hasher};

    let mut hashers = vec![RandomState::new().build_hasher(); m];
    for i in 0..n {
        let g = usize::from_scanner(scanner);
        let mut count = HashMap::new();
        for x in scanner.iter::<usize>(g) {
            *count.entry(x).or_insert(0) += 1;
        }
        for (x, cnt) in count {
            let hasher = &mut hashers[x - 1];
            hasher.write_u32(i);
            hasher.write_u32(cnt);
        }
    }

    let mut count = HashMap::new();
    let mut ans = 1;
    for hasher in hashers {
        let e = count.entry(hasher.finish()).or_insert(0);
        *e += 1;
        ans *= *e;
        ans %= MOD;
    }
    ans
}
