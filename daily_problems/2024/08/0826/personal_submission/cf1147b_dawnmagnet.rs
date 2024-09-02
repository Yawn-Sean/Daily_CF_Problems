fn main() {
    input! { n: usize, m: usize }
    input! { edges: [(usize, usize); m] }
    // eprintln!("{:?}", (n, m, edges));
    let mut factors = BTreeSet::new();
    factors.insert(1);
    for i in 2..n {
        if i * i > n {
            break;
        }
        if n % i == 0 {
            factors.insert(i);
            factors.insert(n / i);
        }
    }

    let mut nedge = vec![vec![]; n];
    for (a, b) in edges {
        let d = b.abs_diff(a);
        let d = d.min(n - d);
        nedge[a - 1].push(d);
        nedge[b - 1].push(d);
    }
    let mut s_hash = vec![0; n];
    for i in 0..n {
        nedge[i].sort_unstable();
        let mut hash = DefaultHasher::new();
        nedge[i].hash(&mut hash);
        s_hash[i] = hash.finish();
    }

    for f in factors {
        let mut correct = true;
        for i in 0..n {
            if s_hash[i] != s_hash[(i + f) % n] {
                correct = false;
                break;
            }
        }
        if correct {
            println!("Yes");
            return;
        }
    }
    println!("No");

    // eprintln!("{:?}", s_hash);
}