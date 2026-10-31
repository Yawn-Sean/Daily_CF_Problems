#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int N = 1 << 15;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }

    vector<int> fac;
    for (int i = 2; i <= 2500; i++) {
        int vis = 0;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                vis = 1;
                break;
            }
        }
        if (!vis) {
            fac.push_back(i);
        }
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        int t = a[i];
        for (int j = 0; j < 15; j++) {
            while (t % fac[j] == 0) {
                t /= fac[j];
            }
        }

        b[i] = t;
    }

    int res = 1e9;
    vector<int> g(2501);
    for (int mask = 0; mask < N; mask++) {
        int ans = 0;
        vector<int> vis(n);
        for (int i = 0; i < 15; i++) {
            if (mask >> i & 1) {
                ans++;
                for (int j = 0; j < n; j++) {
                    if (!vis[j] && a[j] % fac[i] == 0) {
                        vis[j] = 1;
                    }
                }
            }
        }
        int flag = 0;
        for (int j = 0; j < n; j++) {
            if (vis[j]) {
                continue;
            }
            if (b[j] == 1) {
                flag = 1;
                break;
            }
            ans += (g[b[j]] == 0);
            g[b[j]] = 1;
        }

        if (!flag) {
            res = min(res, ans);
        }
        g.assign(2501, 0);
    }

    cout << res;
    return 0;
}