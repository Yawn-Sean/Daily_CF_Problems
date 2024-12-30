#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

void dfs(int root, vector<vector<int>> &g, vector<int> &cnt) { 
    if(g[root].empty()) {
        cnt[root] = 1;
        return ;
    }
    for (auto &node : g[root]) {
        dfs(node, g, cnt);
        cnt[root] += cnt[node];
    }
    return;
}

void solve() { 
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) { 
        int a; cin >> a;
        g[a].emplace_back(i);
    }
    vector<int> cnt(n + 1);
    dfs(1, g, cnt);
    sort(cnt.begin(), cnt.end());
    for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    cout << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
