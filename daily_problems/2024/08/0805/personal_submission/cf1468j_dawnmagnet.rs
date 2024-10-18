fn main() {
    input! { t: i32 }
    for _ in 0..t {
        solve();
    }
}

fn solve() {
    input! { n: usize, m: usize, k: i64 }
    input! { mut r: [(usize, usize, i64); m] }
    r.sort_unstable_by_key(|x| x.2);
    let mut uf = UnionFind::new(n);

    let mut r1 = 1e9 as i64;
    let mut r2 = 0;

    for (u, v, w) in r {
        r1 = r1.min((w - k).abs());
        if uf.unite(u - 1, v - 1) {
            r2 += 0.max(w - k);
        }
    }
    if r2 == 0 {
        println!("{}", r1);
    } else {
        println!("{}", r2);
    }
}
