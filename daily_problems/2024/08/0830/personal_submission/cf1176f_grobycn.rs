//! core logic only
//! submission: https://codeforces.com/problemset/submission/1176/278759326
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut dp = [i64::MIN; 10];
    dp[0] = 0;
    for _ in 0..n {
        let k = usize::from_scanner(scanner);
        let mut mx = [0; 5];
        for (c, d) in scanner.iter::<(usize, i64)>(k) {
            if c != 1 {
                mx[c] = mx[c].max(d);
            } else if d > mx[1] {
                mx[4] = mx[0];
                mx[0] = mx[1];
                mx[1] = d;
            } else if d > mx[0] {
                mx[4] = mx[0];
                mx[0] = d;
            } else if d > mx[4] {
                mx[4] = d;
            }
        }
        // play 0 card
        let mut ndp = dp;
        // play 1 card
        let damage = mx[1].max(mx[2]).max(mx[3]);
        if damage != 0 {
            for i in 1..10 {
                ndp[i] = ndp[i].max(dp[i - 1] + damage);
            }
            ndp[0] = ndp[0].max(dp[9] + 2 * damage);
        }
        // play 2 cards
        let damage1 = mx[1];
        let damage2 = mx[2].max(mx[0]);
        if damage1 != 0 && damage2 != 0 {
            for i in 2..10 {
                ndp[i] = ndp[i].max(dp[i - 2] + damage1 + damage2);
            }
            ndp[0] = ndp[0].max(dp[8] + damage1 + damage2 + damage1.max(damage2));
            ndp[1] = ndp[1].max(dp[9] + damage1 + damage2 + damage1.max(damage2));
        }
        // play 3 cards
        if mx[0] != 0 && mx[1] != 0 && mx[4] != 0 {
            let damage = mx[0] + mx[1] + mx[4];
            for i in 3..10 {
                ndp[i] = ndp[i].max(dp[i - 3] + damage);
            }
            ndp[0] = ndp[0].max(dp[7] + damage + mx[1]);
            ndp[1] = ndp[1].max(dp[8] + damage + mx[1]);
            ndp[2] = ndp[2].max(dp[9] + damage + mx[1]);
        }

        dp = ndp;
    }
    dp.into_iter().max().unwrap()
}
