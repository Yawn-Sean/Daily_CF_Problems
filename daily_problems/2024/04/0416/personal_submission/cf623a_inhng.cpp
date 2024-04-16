#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> in(n + 5), memo(n + 5, -1);
    vector g(n + 5, vector<int>(n + 5));
    for (int i = 1; i <= n; ++i) {
        g[i][i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (not g[i][j]) {
                ++in[i];
                ++in[j];
            }
        }
    }

    function<void(int)> dfs = [&](int x) {
        for (int i = 1; i <= n; ++i) {
            if (not g[x][i] and memo[i] == -1) {
                memo[i] = memo[x] ^ 1;
                dfs(i);
            }
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (memo[i] == -1) {
            memo[i] = 0;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if ((not g[i][j] and memo[i] == memo[j]) or (g[i][j] and in[i] and in[j] and memo[i] != memo[j])) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; ++i) {
        if (not in[i]) {
            cout << 'b';
        } else {
            cout << (memo[i] ? 'a' : 'c');
        }
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
