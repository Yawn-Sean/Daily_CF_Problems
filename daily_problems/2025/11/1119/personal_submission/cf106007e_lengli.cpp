#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    vector<ll> outs;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        string str;
        cin >> str;
        vector<int> s(n);
        for (int i = 0; i < n; ++i) s[i] = str[i] - '0';
        
        vector<vector<int>> path(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v; // 假设输入为 1-based；若为 0-based，请移除这两行
            path[u].push_back(v);
            path[v].push_back(u);
        }
        
        vector<int> queries(q);
        for (int i = 0; i < q; ++i) {
            int x; cin >> x; --x; // queries 是 1-based 输入，转换为 0-based
            queries[i] = x;
        }
        
        int rt = queries[0];
        vector<int> parent(n, -1);
        vector<int> que;
        que.reserve(n);
        que.push_back(rt);
        // 模拟 Python 中的 "for u in que:" 动作（动态扩展的队列）
        for (size_t idx = 0; idx < que.size(); ++idx) {
            int u = que[idx];
            for (int v : path[u]) {
                if (parent[u] != v) {
                    parent[v] = u;
                    que.push_back(v);
                }
            }
        }
        
        vector<int> cols(n, 0);
        ll cnt = n;
        // 把所有 s[i]==0 的节点向上涂色到根（遇到已涂色的停止）
        for (int i = 0; i < n; ++i) {
            if (s[i] == 0) {
                int u = i;
                while (u >= 0 && cols[u] == 0) {
                    cols[u] = 1;
                    --cnt;
                    u = parent[u];
                }
            }
        }
        
        ll total = 0;
        for (int i = 0; i < n; ++i) total += s[i];
        
        for (int u : queries) {
            if (s[u]) {
                s[u] = 0;
                --total;
            }
            int cur = u;
            while (cur >= 0 && cols[cur] == 0) {
                cols[cur] = 1;
                --cnt;
                cur = parent[cur];
            }
            ll ans = cnt * (cnt + 1) / 2 + cnt * (total - cnt);
            outs.push_back(ans);
        }
    }
    
    for (ll x : outs) {
        cout << x << '\n';
    }
    return 0;
}
