#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int const N = 3e5 + 10;
int n, m, ans = 1, res[N];
vector<int> g[N], vec[N];

inline bool cmp(int a, int b) {
    return res[a] < res[b];
}

void dfs(int v, int par = -1) {
    int col = ans, p = (int)vec[v].size() - 1;
    sort(vec[v].begin(), vec[v].end(), cmp);
    for (int x : vec[v]) {
        if (res[x]) {
            continue;
        }
        while (p >= 0 && col == res[vec[v][p]]) {
            col--;
            p--;
        }
        res[x] = col;
        col--;
    }
    for (int u : g[v]) {
        if (u != par) {
            dfs(u, v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int sz;
        cin >> sz;
        ans = max(ans, sz);
        while (sz--) {
            int x;
            cin >> x;
            x--;
            vec[i].push_back(x);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    cout << ans << '\n';
    for (int i = 0; i < m; i++) {
        cout << max(res[i], 1) << ' ';
    }
    return 0;
}