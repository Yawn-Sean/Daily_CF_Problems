// core logic only
// submission: https://codeforces.com/problemset/submission/1442/268475084
const MULTIPLE_TEST: bool = true;
const MOD: usize = 998_244_353;

fn solver(n: usize, k: usize, scanner: &mut Scanner) -> impl Printable {
    let a: Vec<usize> = scanner.iter(n).collect();
    let mut pos = vec![0; n];
    for (i, &x) in a.iter().enumerate() {
        pos[x - 1] = i;
    }

    let b: Vec<usize> = scanner.iter(k).collect();
    let mut need = vec![false; n];
    for &x in &b {
        need[x - 1] = true;
    }

    let mut ans = 1;
    for &x in &b {
        need[x - 1] = false;
        let i = pos[x - 1];
        let mut cnt = 0;
        if i > 0 && !need[a[i - 1] - 1] {
            cnt += 1;
        }
        if i + 1 < n && !need[a[i + 1] - 1] {
            cnt += 1;
        }
        if cnt == 0 {
            return 0;
        }
        ans = (ans * cnt) % MOD;
    }
    ans
}
