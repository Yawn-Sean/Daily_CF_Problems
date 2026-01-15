#include <algorithm>
#include <bit>
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <stack>
#include <map>
#include <numeric>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int MOD = 1e9 + 7;

ll query(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    ll x; cin >> x;
    if (x == -1) exit(0);
    return x;
}

void report(ll m) {
    cout << "! " << m << '\n';
    cout.flush();
}

void solve() {
    int n;
    cin >> n;
    vector<int> deg(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    bool flag = true;
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 3) {
            cout << "NO\n";
            return;
        }
        if (deg[i] == 3 && flag) {
            flag = false;
            root = i;
        }
    }
    if (flag) {
        cout << "YES\n";
        return;
    }

    vector<int> pa(n + 1, -1);
    auto dfs = [&](this auto&& dfs, int u, int fa) -> void {
        for (int v : g[u]) {
            if (v != fa) {
                pa[v] = u;
                dfs(v, u);
            }
        }
    };
    dfs(root, -1);
    vector<char> check(n + 1);
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 3) {
            int cur = i;
            while (cur != -1 && !check[cur]) {
                check[cur] = true;
                cur = pa[cur];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (check[i]) {
            int cnt = 0;
            for (int j : g[i]) {
                if (check[j]) cnt++;
            }
            if (cnt > 2) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}