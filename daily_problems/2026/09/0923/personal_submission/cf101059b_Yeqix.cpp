#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int N = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> mx(N + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mx[x].push_back(i);
    }

    int ans = 1e9;
    for (int i = 1; i <= N; i++) {
        int m = mx[i].size();
        int res = m, mxx = 0;
        for (int j = 0; j < m; j++) {
            int v = (mx[i][(j + 1) % m] - mx[i][j] - 1 + n) % n;
            res += v, mxx = max(mxx, v);
        }
        if (m) {
            ans = min(ans, res + mxx);
        }
    }

    cout << ans;
    return 0;
}