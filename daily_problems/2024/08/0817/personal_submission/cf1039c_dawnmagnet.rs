fn main() {
    input! { n: usize, m: usize, k: usize }
    input! { key: [i64; n] }
    input! { edges: [(usize, usize); m] }
    let pow2_len = (n + 1).max(k + 1);
    let mut pow2 = vec![1i64; pow2_len];
    for i in 1..pow2_len {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }
    let mut xor_values = HashMap::new();
    for (a, b) in edges {
        let e = key[a - 1] ^ key[b - 1];
        xor_values.entry(e).or_insert(vec![]).push((a - 1, b - 1));
    }
    let mut ans = 0;
    let mut ds = DisjointSet::new(n);

    for v in xor_values.values() {
        let mut r = n;
        for &(a, b) in v.iter() {
            if ds.merge(a, b) {
                r -= 1;
            }
        }
        ans += pow2[r];
        ans %= MOD;
        for &(a, b) in v.iter() {
            ds.parent[a] = -1;
            ds.parent[b] = -1;
        }
    }
    ans += (pow2[k] - xor_values.len() as i64) * (pow2[n]) % MOD;
    ans %= MOD;
    println!("{}", ans);
}
