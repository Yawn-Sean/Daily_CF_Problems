//! core logic only
//! submission: https://codeforces.com/problemset/submission/342/310570397
const MULTIPLE_TEST: bool = false;
const MOD: i64 = 1_000_000_007;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut table: Vec<_> = scanner.iter(3).map(String::into_bytes).collect();
    let (r, c) = (0..3)
        .flat_map(|r| (0..n).map(move |c| (r, c)))
        .find(|&(r, c)| table[r][c] == b'O')
        .unwrap();

    let dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)];
    let mut possible_setup = vec![];
    for &(dr, dc) in dirs.iter() {
        let mut slot = 0;
        for d in 1..=2 {
            let r = r as i32 + dr * d;
            let c = c as i32 + dc * d;
            if 0 <= r && r < 3 && 0 <= c && c < n as i32 {
                let (r, c) = (r as usize, c as usize);
                if table[r][c] == b'.' {
                    slot += 1;
                }
            }
        }
        if slot == 2 {
            possible_setup.push((dr, dc));
        }
    }

    let mut ans = 0;
    let m = possible_setup.len();
    for msk in 1..1 << m {
        let mut sign = -1;
        for (i, &(dr, dc)) in possible_setup.iter().enumerate() {
            if msk & (1 << i) != 0 {
                sign = -sign;
                for d in 1..=2 {
                    let r = r as i32 + dr * d;
                    let c = c as i32 + dc * d;
                    table[r as usize][c as usize] = b'X';
                }
            }
        }

        let mut dp = [0; 8];
        dp[0] = 1;
        for c in 0..n {
            let mut ndp = [0; 8];
            let mut exist = 0;
            for r in 0..3 {
                if table[r][c] != b'.' {
                    exist |= 1 << r;
                }
            }
            for (pmsk, &cnt) in dp.iter().enumerate() {
                if pmsk & exist != 0 || cnt == 0 {
                    continue;
                }
                let empty_mask = 7 ^ pmsk ^ exist;
                let mut nmsk = empty_mask;
                ndp[nmsk] = (ndp[nmsk] + cnt) % MOD;
                while nmsk > 0 {
                    nmsk = (nmsk - 1) & empty_mask;
                    let vert_mask = empty_mask ^ nmsk;
                    if vert_mask % 3 == 0 {
                        ndp[nmsk] = (ndp[nmsk] + cnt) % MOD;
                    }
                }
            }
            dp = ndp;
        }
        ans = (ans + MOD + sign * dp[0]) % MOD;

        // restore table
        for (i, &(dr, dc)) in possible_setup.iter().enumerate() {
            if msk & (1 << i) != 0 {
                sign = -sign;
                for d in 1..=2 {
                    let r = r as i32 + dr * d;
                    let c = c as i32 + dc * d;
                    table[r as usize][c as usize] = b'.';
                }
            }
        }
    }
    ans
}
