#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
#define dbg(x) cerr << #x << " = " << (x) << endl;
#define vdbg(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << endl;


void solve() {  
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int a = 1; a <= n; ++a) {
        for (int b : g[a]) {
            for (int i = 0; i < min(3, (int)g[a].size()); ++i) {
                for (int j = 0; j < min(3, (int)g[b].size()); ++j) {
                    int c = g[a][i], d = g[b][j];
                    if (c != b && c != d && d != a) {
                        cout << c << "\n" << a << "\n" << b << "\n" << d << "\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "-1\n";
}                                                                     

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);
  
    int T = 1;
    // cin >> T;  
    while (T--) solve();    
    return 0;
}   
