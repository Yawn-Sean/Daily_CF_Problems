#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 200001;
constexpr int MX_LOG_N = 18;
int a[MXN];
int b[MXN];
vector<int> g[MXN];
int p[MXN][MX_LOG_N];
long long w[MXN][MX_LOG_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int d = 0; d < MX_LOG_N; d++) {
            p[i][d] = -1;
        }
    }

    for (int i = 1; i < n; i++) {
        int pi, wi;
        cin >> pi >> wi;
        g[pi - 1].push_back(i);
        p[i][0] = pi - 1;
        w[i][0] = wi;
    }

    function<void(int)> dfs = [&] (int u) {
        for (auto& v : g[u]) {
            for (int d = 1; d < MX_LOG_N; d++) {
                if (p[v][d - 1] == -1) break;
                w[v][d] = w[v][d - 1] + w[p[v][d - 1]][d - 1];
                p[v][d] = p[p[v][d - 1]][d - 1];
            }
            dfs(v);
        }
    };

    dfs(0);

    for (int v = 1; v < n; v++) {
        int u = v;
        long long x = a[u];
        for (int d = MX_LOG_N - 1; d >= 0; d--) {
            if (p[u][d] == -1 || w[u][d] > x) continue;
            x -= w[u][d];
            u = p[u][d];
        }
        if (p[v][0] != -1) b[p[v][0]]++;
        if (p[u][0] != -1) b[p[u][0]]--;
    }

    function<void(int)> dfs2 = [&] (int u) {
        for (auto& v : g[u]) {
            dfs2(v);
            b[u] += b[v];
        }
    };

    dfs2(0);

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}

