//! core logic only
//! submission: https://codeforces.com/problemset/submission/305/310726170
const MULTIPLE_TEST: bool = false;
const MOD: usize = 1_000_000_007;

fn solver(n: usize, m: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let (mut first, mut last) = (usize::MAX, usize::MAX);
    let mut cnt = 0;
    for (u, v) in scanner.iter::<(usize, usize)>(m) {
        if u + 1 + k == v {
            cnt += 1;
            if first == usize::MAX {
                first = u;
            }
            last = u;
        } else if u + 1 != v {
            return 0;
        }
    }
    // first != usize::MAX && first + k + 1 <= last
    if first.saturating_add(k) <= last - 1 {
        return 0;
    }

    let mut pow = vec![1; k + 1];
    for i in 1..=k {
        pow[i] = (pow[i - 1] * 2) % MOD;
    }
    let mut ans = 0;
    for i in (1..=n).rev() {
        if i + 1 + k > n {
            continue;
        }
        // Assume that for point j in [i + 1, n], there is no edge from j to j + k + 1.
        // Then we add an edge from i to i + 1 + k
        let l = i.saturating_sub(k + 1);
        // For point j in [1, l], make sure that there is no edge from j to j + k + 1
        if first > l {
            // For some point j in [l + 1, i), we could add edge from j to j + k + 1
            let slot = i - 1 - l + usize::from(i == last) - cnt;
            ans = (ans + pow[slot]) % MOD;
        }
        if i == last {
            return ans;
        }
    }
    // add special case: 1 -> 2 -> 3 -> ... -> n
    (ans + 1) % MOD
}
