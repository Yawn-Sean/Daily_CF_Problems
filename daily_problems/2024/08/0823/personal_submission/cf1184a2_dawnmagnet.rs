fn init_prime(n: usize) -> Vec<usize> {
    let mut primes = vec![];
    let mut is_prime = vec![true; n];
    let mut min_prime_factors = vec![0; n];

    for i in 2..n {
        if is_prime[i] {
            primes.push(i);
            min_prime_factors[i] = i;
        }
        for &j in &primes {
            if i * j < n {
                is_prime[j * i] = false;
                min_prime_factors[j * i] = j;
                if i % j == 0 {
                    break;
                }
            }
        }
    }
    min_prime_factors
}
fn get_prime_factors(n: usize, min_prime_factors: &Vec<usize>) -> Vec<usize> {
    let mut prime_factors = vec![];
    let mut n = n;
    while n > 1 {
        let p = min_prime_factors[n];
        prime_factors.push(p);
        n /= p;
    }
    prime_factors
}
fn get_factors(prime_factors: &Vec<usize>) -> Vec<usize> {
    let mut factors = vec![1];
    for &p in prime_factors {
        let mut new_factors = vec![];
        for &f in &factors {
            new_factors.push(f * p);
        }
        factors.extend(new_factors);
    }
    factors.sort_unstable();
    factors.dedup();
    factors.pop();
    factors
}
fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}
fn main() {
    input! { n: usize }
    input! { s: String }

    let s = s.into_bytes();
    let min_prime_factors = init_prime(n + 10);
    let factors = get_factors(&get_prime_factors(n, &min_prime_factors));
    let mut valid = HashSet::new();
    for k in factors {
        let mut d = vec![0; k];
        for i in 0..n {
            if s[i] == b'1' {
                d[i % k] ^= 1;
            }
        }
        let ds = d.iter().sum::<i32>();
        if ds == 0 {
            valid.insert(k);
        }
    }
    let mut res = 0;
    for i in 1..n {
        let j = gcd(i, n);
        if valid.contains(&j) {
            res += 1;
        }
    }
    if !s.contains(&b'1') {
        res += 1;
    }
    println!("{}", res);