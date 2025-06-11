// core logic only
// submission: https://codeforces.com/problemset/submission/863/267345278
const MULTIPLE_TEST: bool = false;

fn solver(mut k: usize, mut a: usize, mut b: usize, scanner: &mut Scanner) -> impl Printable {
    let mata: Vec<Vec<usize>> = (0..3).map(|_| scanner.iter(3).collect()).collect();
    let matb: Vec<Vec<usize>> = (0..3).map(|_| scanner.iter(3).collect()).collect();
    let mut vis = [[(usize::MAX, 0, 0); 3]; 3];
    let (mut alice, mut bob) = (0, 0);
    let mut clock = 0;
    while vis[a - 1][b - 1].0 == usize::MAX && k > 0 {
        match (a, b) {
            (1, 2) | (2, 3) | (3, 1) => bob += 1,
            (2, 1) | (3, 2) | (1, 3) => alice += 1,
            _ => {}
        }
        k -= 1;
        if k == 0 {
            return (alice, bob);
        }
        vis[a - 1][b - 1] = (clock, alice, bob);
        clock += 1;
        (a, b) = (mata[a - 1][b - 1], matb[a - 1][b - 1]);
    }
    let period = clock - vis[a - 1][b - 1].0;
    let (q, r) = (k / period, k % period);
    let (exta, extb) = match (a, b) {
        (1, 2) | (2, 3) | (3, 1) => (0, 1),
        (2, 1) | (3, 2) | (1, 3) => (1, 0),
        _ => (0, 0),
    };
    alice += (alice + exta - vis[a - 1][b - 1].1) * q;
    bob += (bob + extb - vis[a - 1][b - 1].2) * q;

    for _ in 0..r {
        match (a, b) {
            (1, 2) | (2, 3) | (3, 1) => bob += 1,
            (2, 1) | (3, 2) | (1, 3) => alice += 1,
            _ => {}
        }
        (a, b) = (mata[a - 1][b - 1], matb[a - 1][b - 1]);
    }
    (alice, bob)
}
