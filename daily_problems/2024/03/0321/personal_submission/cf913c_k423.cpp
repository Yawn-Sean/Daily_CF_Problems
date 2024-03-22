/**
 * Created by 5cm/s on 2024/03/21 10:15:49.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>

using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

using i64 = int64_t;

void elysia() {
    int n;
    i64 l;
    cin >> n >> l;
    vector<i64> dp(31, 1e18);
    for (int i = 0; i < n; ++i) cin >> dp[i];
    for (int i = 1; i <= 30; ++i) {
        dp[i] = min(dp[i], dp[i - 1] * 2);
    }
    i64 ans = 1e18;
    while (__lg(l) <= 30) {
        i64 cur = 0;
        for (int i = 0; i <= 30; ++i) {
            if (l >> i & 1) {
                cur += dp[i];
            }
        }
        ans = min(ans, cur);
        l += l & -l;
    }
    cout << ans << endl;
}

int main() {
#ifdef MEGURINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    clock_t start = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) elysia();
#ifdef MEGURINE
    cout << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}
