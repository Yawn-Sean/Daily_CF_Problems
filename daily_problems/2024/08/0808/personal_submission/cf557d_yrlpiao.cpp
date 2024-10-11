#include <iostream>           
#include <vector>    
#include <cstring>     
using namespace std;  

const int N = 3e5 + 10;

int n, m, col[N] {};
vector<int> e[N];

int dfs(int u, int c[], int t) {
    col[u] = t;
    c[t]++; 
    for (int v : e[u]) {
        if (col[v] == t) return 0;
        if (col[v] == -1 && !dfs(v, c, 1 - t)) return 0;
    }
    return 1;
}

void yrlpSolve() {
	cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (!m) return cout << 3 << " " << 1LL * n * (n - 1) * (n - 2) / 6, void();
    long long ans = 0;
    memset(col, -1, sizeof col);
    for (int i = 1; i <= n; i++) {
        if (col[i] == -1) {
            int c[2] {};
            if (!dfs(i, c, 1)) return cout << 0 << " " << 1, void();
            ans += 1LL * c[0] * (c[0] - 1) / 2 + 1LL * c[1] * (c[1] - 1) / 2;
        }
    }
    if (!ans) cout << 2 << " " << 1LL * m * (n - 2);
    else cout << 1 << " " << ans;
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}

