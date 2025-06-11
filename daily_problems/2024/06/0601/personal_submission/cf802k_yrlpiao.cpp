#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> dfs(int node, int fa, int k, vector<vector<pair<int, int>>>& ed) {
    vector<pair<int, int>> v;
    for (auto x : ed[node]) {
        if (x.first == fa) continue;
        auto p = dfs(x.first, node, k, ed);
        p.first += x.second, p.second += x.second;
        v.push_back(p);
    }
    sort(v.rbegin(), v.rend());
    pair<int, int> ret = {0, 0};
    if (v.size() < k) {
        for (auto x : v) ret.first += x.first;
        for (auto x : v) {
            ret.second = max(ret.second, ret.first - x.first + x.second);
        }
    } else {
        for (int i = 0; i < k - 1; i++) ret.first += v[i].first;
        for (int i = 0; i < k - 1; i++) {
            ret.second = max(ret.second, ret.first - v[i].first + v[k - 1].first + v[i].second);
        }
        for (int i = k - 1; i < v.size(); i++) {
            ret.second = max(ret.second, ret.first + v[i].second);
        }
    }
    return ret;
}

void yrlpSolve() {
    int n, k; cin >> n >> k;
    vector<vector<pair<int, int>>> ed(n + 10, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w;
        ed[u].push_back({v, w});
        ed[v].push_back({u, w});
    }
    cout << dfs(0, -1, k, ed).second;
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
