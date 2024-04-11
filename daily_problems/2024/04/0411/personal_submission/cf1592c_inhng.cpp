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
    int n, k, sum = 0, ans = 0;
    cin >> n >> k;
    vector<int> a(n), g[n + 1];
    for (int &ai : a) {
        cin >> ai;
        sum ^= ai;
    }
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    if (not sum) {
        cout << "YES" << endl;
        return;
    }
    if (k == 2) {
        cout << "NO" << endl;
        return;
    }
    function<int(int, int)> dfs = [&](int u, int father) -> int {
        int mid = a[u - 1];
        for (int v : g[u]) {
            if (v == father) {
                continue;
            }
            mid ^= dfs(v, u);
        }
        if (sum == mid) {
            ++ans;
            return 0;
        }
        return mid;
    };

    dfs(1, -1);
    cout << (ans < 2 ? "NO" : "YES") << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
