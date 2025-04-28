//! core logic only
//! submission: https://codeforces.com/problemset/submission/291/312563537
const MULTIPLE_TEST: bool = false;
const MOD: u64 = 1_000_000_007;

fn random() -> u64 {
    use std::collections::hash_map::RandomState;
    use std::hash::{BuildHasher, Hasher};
    RandomState::new().build_hasher().finish()
}

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut adj = vec![vec![]; n];
    let mut s = Vec::with_capacity(n - 1);
    for (i, (pi, si)) in scanner.iter::<(usize, String)>(n - 1).enumerate() {
        adj[pi - 1].push(i + 1);
        s.push(si);
    }
    let t = String::from_scanner(scanner);

    let base = random() % 200 + 100;
    let bias = random() % 50;
    let hash = |state: u64, b: u8| (state * base + (b - b'a') as u64 + bias) % MOD;
    let mut pow = 1;
    let mut hash_t = 0;
    for b in t.bytes() {
        hash_t = hash(hash_t, b);
        pow = (pow * base) % MOD;
    }
    let check = |hash_initial: u64, hash_final: u64| {
        (hash_final + MOD - (hash_initial * pow) % MOD) % MOD == hash_t
    };

    fn dfs(
        adj: &[Vec<usize>],
        s: &[String],
        cur: usize,
        len_t: usize,
        hashes: &mut Vec<u64>,
        ans: &mut usize,
        hash: &impl Fn(u64, u8) -> u64,
        check: &impl Fn(u64, u64) -> bool,
    ) {
        let l = hashes.len();
        let h = *hashes.last().unwrap();
        for &child in &adj[cur] {
            let si = &s[child - 1];
            let mut h = h;
            for b in si.bytes() {
                h = hash(h, b);
                hashes.push(h);
                if let Some(&hl) = hashes.get(hashes.len().wrapping_sub(len_t + 1)) {
                    if check(hl, h) {
                        *ans += 1;
                    }
                }
            }
            dfs(adj, s, child, len_t, hashes, ans, hash, check);
            hashes.truncate(l);
        }
    }

    let mut hashes = vec![0];
    let mut ans = 0;
    dfs(&adj, &s, 0, t.len(), &mut hashes, &mut ans, &hash, &check);
    ans
}
