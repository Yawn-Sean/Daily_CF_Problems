// core logic only
// submission: https://codeforces.com/contest/1027/submission/254089413
const MULTIPLE_TEST: bool = false;

fn solver(cost: Vec<u32>, scanner: &mut Scanner) -> impl Printable {
    let n = cost.len();
    let arr: Vec<_> = scanner.iter(n).map(|x: usize| x - 1).collect();
    let mut vis = vec![-1i32; n];
    let mut clock = 0;

    let mut ans = 0;
    for mut i in 0..n {
        if vis[i] >= 0 {
            continue;
        }
        let start_at = clock;
        while vis[i] == -1 {
            vis[i] = clock;
            clock += 1;
            i = arr[i];
        }

        if vis[i] >= start_at {
            let mut mn = cost[i];
            let mut cur = arr[i];
            while cur != i {
                mn = mn.min(cost[cur]);
                cur = arr[cur];
            }
            ans += mn;
        }
    }

    ans
}
