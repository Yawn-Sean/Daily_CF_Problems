fn get_primes(n: usize) -> Vec<usize> {
    let mut primes = vec![];
    let mut is_prime = vec![true; n];
    for j in 2..n {
        if is_prime[j] {
            primes.push(j);
        }
        for i in 0..primes.len() {
            if j * primes[i] >= n {
                break;
            }
            is_prime[j * primes[i]] = false;
            if j % primes[i] == 0 {
                break;
            }
        }
    }
    primes
}
fn main() {
    let primes = get_primes(100005);
    let primes = primes.iter().map(|&x| x).collect::<BTreeSet<_>>();
    input! { n: usize, a: [i32; n] }
    let mut origin = a
        .iter()
        .enumerate()
        .map(|(a, &b)| (b, a))
        .collect::<Vec<_>>();
    let mut sorted = origin.clone();
    sorted.sort_unstable();
    let mut pos = HashMap::new();
    for (i, a) in origin.iter().enumerate() {
        pos.insert(*a, i);
    }
    // eprintln!("{:?}", sorted);
    // eprintln!("{:?}", origin);
    let mut ans = vec![];
    for i in 0..n {
        if origin[i] != sorted[i] {
            let mut j = pos[&sorted[i]];
            while j != i {
                let max_prime = *primes.range(..=(j - i + 1)).last().unwrap();
                // println!("{} {}", max_prime, j + 1);
                ans.push((j + 2 - max_prime, j + 1));
                origin.swap(j + 1 - max_prime, j);
                pos.insert(origin[j + 1 - max_prime], j + 1 - max_prime);
                pos.insert(origin[j], j);
                j = j + 1 - max_prime;
            }
        }
    }
    println!("{}", ans.len());
    for (a, b) in ans {
        println!("{} {}", a, b);
    }
}
