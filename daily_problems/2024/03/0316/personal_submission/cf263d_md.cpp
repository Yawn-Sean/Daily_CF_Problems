#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n, -1);
    stack<int> st;
    int time = 0;
    auto dfs = [&](auto self, int cur) -> void {
        vis[cur] = time++;
        st.push(cur);
    
        for (auto next : adj[cur]) {
            if (vis[next] == -1) {
                self(self, next);
            } else if (vis[cur] - vis[next] >= k) {
                cout << vis[cur] - vis[next] + 1 << endl;
                while (!empty(st)) {
                    cout << st.top() + 1 << " ";
                    if (st.top() == next) {
                        exit(0);
                    }
                    st.pop();
                }
            }
        }
    };
    dfs(dfs, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}