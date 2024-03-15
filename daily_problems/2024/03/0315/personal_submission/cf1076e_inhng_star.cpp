#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, m;
    cin >> n;
    vector<int> g[n + 1], ans(n + 1), add(n + 1);
    vector<PII> op[n + 1];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    cin >> m;
    while (m--) {
        int v, d, x;
        cin >> v >> d >> x;
        op[v].emplace_back(d, x);
    }

    // 当前节点，父节点，层数高度，总和
    function<void(int, int, int, int)> dfs = [&](int u, int pre, int h, int sum) {
        // 来到这个高度
        for (auto [d, x] : op[u]) { // 差分(树状数组)，这一段的数全部 +x
            add[h] += x;
            if (h + d + 1 <= n) {
                add[h + d + 1] -= x;
            }
        }
        sum += add[h];
        ans[u] = sum;
        for (int v : g[u]) {
            if (v ^ pre) { // 进行下一层遍历
                dfs(v, u, h + 1, sum);
            }
        }
        // 离开这个高度
        for (auto [d, x] : op[u]) { // 差分(树状数组)，这一段的数全部 -x
            add[h] -= x;
            if (h + d + 1 <= n) {
                add[h + d + 1] += x;
            }
        }
    };

    dfs(1, -1, 0, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
