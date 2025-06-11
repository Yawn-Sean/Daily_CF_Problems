#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> coord(n);
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        coord[i] = {x, y, z};
    }
    vector<int> ans(n);
    ranges::iota(ans, 0);
    ranges::sort(ans, [&](const int &i, const int &j) { return coord[i] < coord[j]; });
    map<int, vector<int>> X;
    vector<int> vis(n);
    for (auto i: ans) X[get<0>(coord[i])].push_back(i);
    for (auto &[x, v]: X) {
        map<int, vector<int>> Y;
        int m = v.size();
        for (auto i: v) Y[get<1>(coord[i])].push_back(i);
        for (auto &[y, v2]: Y) {
            for (int j = 0; j < v2.size() - 1; j += 2) {
                println("{} {}", v2[j] + 1, v2[j+1] + 1);
                vis[v2[j]] = vis[v2[j+1]] = true;
                m -= 2;
            }
        }
        for (int i = 0, j = 0; i < v.size() && (j % 2 || j < m - 1); ++i)
            if (!vis[v[i]]) print("{}{}", v[i] + 1, (++j % 2 ? ' ' : '\n')), vis[v[i]] = true;
    }
    for (int i = 0, j = 0; i < n; ++i) if (!vis[ans[i]]) print("{}{}", ans[i] + 1, (++j % 2 ? ' ' : '\n'));
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
