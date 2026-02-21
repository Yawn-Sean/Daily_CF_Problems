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
#include <numbers>
#include <cmath>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;

const int N = 1e5;
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
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].emplace_back(v, c);
    }
    vector<int> visited(n + 1);
    queue<pii> q;
    visited[1] = -1;
    q.emplace(1, -1);
    while (!q.empty()) {
        auto [u, prev_c] = q.front();
        q.pop();
        for (auto& [v, c] : g[u]) {
            if (c == prev_c) continue;
            if (visited[v] == 0) {
                visited[v] = c;
                q.emplace(v, c);
            } else if (visited[v] != c && visited[v] != -1) {
                visited[v] = -1;
                q.emplace(v, -1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i] != 0) cout << i << ' ';
    }
    cout << '\n';
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