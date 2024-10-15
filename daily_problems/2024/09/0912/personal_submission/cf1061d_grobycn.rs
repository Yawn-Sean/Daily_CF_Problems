//! core logic only
//! submission: https://codeforces.com/contest/1061/submission/281483122
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, x: usize, y: usize, scanner: &mut Scanner) -> impl Printable {
    use std::cmp::Reverse;
    use std::collections::{binary_heap::PeekMut, BinaryHeap};

    let mut shows: Vec<(usize, usize)> = scanner.iter(n).collect();
    shows.sort_unstable_by_key(|show| show.0);
    // x + y * (b - a) = z + y * (b + 1 - a)
    let z = x - y;
    let mut candidates = BinaryHeap::new();
    let mut recycle: BinaryHeap<Reverse<usize>> = BinaryHeap::new();
    let mut ans = Mod(0);

    for &(l, r) in &shows {
        ans = ans + Mod(r + 1 - l) * Mod(y);
        while let Some(top) = recycle.peek_mut() {
            if top.0 < l {
                candidates.push(top.0);
                PeekMut::pop(top);
            } else {
                break;
            }
        }
        ans = match candidates.pop() {
            Some(i) if y * (l - 1 - i) < z => ans + Mod(l - 1 - i) * Mod(y),
            _ => ans + Mod(z),
        };
        recycle.push(Reverse(r));
    }
    ans.0
}

struct Mod(usize);

use std::ops::{Add, Mul};

impl Add for Mod {
    type Output = Self;
    fn add(self, rhs: Self) -> Self {
        Mod((self.0 + rhs.0) % MOD)
    }
}

impl Mul for Mod {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self {
        Mod((self.0 * rhs.0) % MOD)
    }
}
