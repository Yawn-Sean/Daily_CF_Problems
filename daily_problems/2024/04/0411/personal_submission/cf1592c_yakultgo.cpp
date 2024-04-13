#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int xor_sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xor_sum ^= a[i];
    }
    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (xor_sum == 0) {
        cout << "YES" << endl;
        return;
    }
    // 三个连通块需要断开两条边
    if (k == 2) {
        cout << "NO" << endl;
        return;
    }
    bool flag = false;
    vector<int> cnt(n + 1, 0), val(n + 1, 0);
    function<void(int, int)> dfs = [&](int x, int fa) {
        val[x] = a[x];
        for (int y : g[x]) {
            if (y == fa) continue;
            dfs(y, x);
            cnt[x] += cnt[y];
            val[x] ^= val[y];
        }
        if (cnt[x] >= 2 || cnt[x] == 1 && val[x] == 0) flag = true;
        // 一整个连通块的异或和为xor_sum
        if (cnt[x] == 0 && val[x] == xor_sum) cnt[x] = 1;
    };
    dfs(1, 0);
    cout << (flag ? "YES" : "NO") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}