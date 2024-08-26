//! core logic only
//! submission: https://codeforces.com/problemset/submission/1147/278262262
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, m: usize, scanner: &mut Scanner) -> impl Printable {
    let edges: std::collections::HashSet<(usize, usize)> = scanner.iter(m).collect();
    let check = |k: usize| {
        for &(a, b) in &edges {
            let (a, b) = ((a - 1 + k) % n + 1, (b - 1 + k) % n + 1);
            if !edges.contains(&(a, b)) && !edges.contains(&(b, a)) {
                return false;
            }
        }
        true
    };

    let mut m = n;
    let mut p = 2;
    while p * p <= m {
        if m % p == 0 {
            if check(n / p) {
                return "Yes";
            }
            while m % p == 0 {
                m /= p;
            }
        }
        p += 1;
    }

    if m != 1 && check(n / m) {
        return "Yes";
    }
    "No"
}
