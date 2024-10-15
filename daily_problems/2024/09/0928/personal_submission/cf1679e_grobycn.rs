//! core logic only
//! submission: https://codeforces.com/contest/1679/submission/283856639
const MULTIPLE_TEST: bool = false;
const MOD: usize = 998_244_353;

fn solver(n: usize, s: String, q: usize, scanner: &mut Scanner) -> impl Printable {
    let qcnt = s.bytes().filter(|&b| b == b'?').count();
    let s = s.as_bytes();
    let mut count = vec![vec![qcnt; n]; n];
    let mut mask = vec![vec![0; n]; n];
    for len in 2..=n {
        for l in 0..=n - len {
            let r = l + len - 1;
            mask[l][r] = mask[l + 1][r - 1];
            if mask[l][r] == usize::MAX {
                continue;
            }
            count[l][r] = count[l + 1][r - 1];
            match (s[l], s[r]) {
                (b'?', b'?') => count[l][r] -= 1,
                (b'?', b) | (b, b'?') => {
                    count[l][r] -= 1;
                    mask[l][r] |= 1 << (b - b'a');
                }
                (a, b) if a != b => mask[l][r] = usize::MAX,
                _ => {}
            }
        }
    }
    let mut powers = vec![vec![]; 17];
    for (ps, x) in powers.iter_mut().zip(1..) {
        ps.reserve(n + 1);
        let mut p = 1;
        ps.push(p);
        for _ in 1..=n {
            p = (p * x) % MOD;
            ps.push(p);
        }
    }

    let mut acc = vec![vec![0; 1 << 17]; 17];
    for l in 0..n {
        for r in l..n {
            if mask[l][r] != usize::MAX {
                let msk = mask[l][r];
                for (acc, powers) in acc.iter_mut().zip(&powers) {
                    acc[msk] += powers[count[l][r]];
                    acc[msk] %= MOD;
                }
            }
        }
    }

    for acc in acc.iter_mut() {
        for i in 0..17 {
            for msk in 0usize..1 << 17 {
                if msk & (1 << i) != 0 {
                    acc[msk] += acc[msk ^ (1 << i)];
                    acc[msk] %= MOD;
                }
            }
        }
    }

    let ans: Vec<_> = scanner
        .iter::<String>(q)
        .map(|set| {
            let msk: usize = set.bytes().fold(0, |acc, b| acc | (1 << (b - b'a')));
            acc[set.len() - 1][msk]
        })
        .collect();
    Sep::<_, '\n'>(ans)
}
