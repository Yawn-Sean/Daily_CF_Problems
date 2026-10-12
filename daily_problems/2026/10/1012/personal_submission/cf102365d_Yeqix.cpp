#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr i64 inf = 1e12;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<i64> l(m + 1), r(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> l[i];
    }

    vector<i64> dist(n * 2 + 1, inf);
    priority_queue<array<i64, 2>, vector<array<i64, 2>>, greater<array<i64, 2>>> que;
    que.push({dist[n] = 0, n});
    while (!que.empty()) {
        auto [dis, u] = que.top();
        que.pop();
        if (dis != dist[u]) {
            continue;
        }
        for (int i = 1; i <= m; i++) {
            if (u + i <= n * 2 && dist[u + i] > dist[u] + r[i]) {
                dist[u + i] = dist[u] + r[i];
                que.push({dist[u + i], u + i});
            }
            if (u - i >= 0 && dist[u - i] > dist[u] + l[i]) {
                dist[u - i] = dist[u] + l[i];
                que.push({dist[u - i], u - i});
            }
        }
    }

    vector<i64> fl(n + 1, inf), fr(n + 1, inf);
    for (int i = 0; i <= n; i++) {
        fl[i] = dist[n - i], fr[i] = dist[n + i];
    }

    vector<vector<i64>> L(n + 2, vector<i64>(n + 2)), R(n + 2, vector<i64>(n + 2));
    vector<i64> lenl(n + 1, -1), lenr(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        L[i][i] = fl[1], R[i][i] = fr[1];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if (lenl[len] != -1) {
                L[i][j] = lenl[len];
            } else {
                i64 ans = inf;
                for (int k = j; k >= i; k--) {
                    ans = min(ans, max(L[i][k - 1], R[k + 1][j]) + fl[j - k + 1]);
                }
                L[i][j] = lenl[len] = ans;
            }
            if (lenr[len] != -1) {
                R[i][j] = lenr[len];
            } else {
                i64 ans = inf;
                for (int k = i; k <= j; k++) {
                    ans = min(ans, max(L[i][k - 1], R[k + 1][j]) + fr[k - i + 1]);
                }
                R[i][j] = lenr[len] = ans;
            }
        }
    }

    cout << R[2][n];
    return 0;
}