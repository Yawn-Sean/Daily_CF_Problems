/*----------------------------------------------------------*/
/* Author : KaMtuo                                          */
/* Email : kamtuo@qq.com                                    */
/* Creation_time : 2025-03-17 14:46                         */
/* Software : Visual Studio Code                            */
/*                                                          */
/*  ██╗  ██╗ █████╗ ███╗   ███╗████████╗██╗   ██╗ ██████╗   */
/*  ██║ ██╔╝██╔══██╗████╗ ████║╚══██╔══╝██║   ██║██╔═══██╗  */
/*  █████╔╝ ███████║██╔████╔██║   ██║   ██║   ██║██║   ██║  */
/*  ██╔═██╗ ██╔══██║██║╚██╔╝██║   ██║   ██║   ██║██║   ██║  */
/*  ██║  ██╗██║  ██║██║ ╚═╝ ██║   ██║   ╚██████╔╝╚██████╔╝  */
/*  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝   ╚═╝    ╚═════╝  ╚═════╝   */
/*----------------------------------------------------------*/

#ifndef KAMTUO_LEETCODE

void solve() {
    int n;
    cin >> n;
    map<int, int> ii;
    vector a(n + 1, 0ll);
    std::function<LL (LL, LL)> gcd = [&] (LL a, LL b) -> LL {
        if (!b) return a;
        return gcd(b, a % b);
    };
    auto lcm = [&] (LL a, LL b) -> LL {
        return 1ll * a * b / gcd(a, b);
    };
    int ans = 0;
    a[0] = 1;
    int mx = 0, lc;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        mx = max(a[i], 1ll * mx);
        ii[a[i]] ++;
        a[0] = lcm(a[0], a[i]);
        if (a[0] > 1000000000) {
            cout << n << "\n";
            return;
        }
    }
    if (mx != a[0]) {
        cout << n << "\n";
    } else {
        for (int i = 2; 1ll * i * i <= a[0]; i ++) {
            if (a[0] % i == 0) {
                int now = i, nowl = 1;
                int res = 0;
                for (LL j = 1; j <= n; j ++) {
                    if (now % a[j] == 0) {
                        nowl = lcm(a[j], nowl);
                        res ++;
                    }
                }
                if (nowl == now && ii[nowl] == 0) {
                    ans = max(ans, res);
                } 
                now = a[0] / i, nowl = 1;
                res = 0;
                for (int j = 1; j <= n; j ++) {
                    if (now % a[j] == 0) {
                        nowl = lcm(a[j], nowl);
                        res ++;
                    }
                }
                if (nowl == now && ii[nowl] == 0) {
                    ans = max(ans, res);
                } 
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
    return 0;
}

#endif

/*

*/
