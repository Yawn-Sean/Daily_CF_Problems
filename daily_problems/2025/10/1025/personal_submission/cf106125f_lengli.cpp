#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    if ((n & 1) || n > 2005) {
        cout << "impossible";
        return 0;
    }

    vector<vector<char>> path(n, vector<char>(n, 1));
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        path[u][v] = 0;
        path[v][u] = 0;
    }
    for (int i = 0; i < n; ++i) path[i][i] = 0;

    vector<int> color(n, -1);        
    vector<int> cnts;               
    vector<vector<int>> groups;      

    for (int s = 0; s < n; ++s) {
        if (color[s] != -1) continue;

        vector<int> stack;
        stack.push_back(s);
        color[s] = 0;
        vector<int> comp;
        int cnt1 = 0;

        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            comp.push_back(u);
            if (color[u] == 1) ++cnt1;

            for (int v = 0; v < n; ++v) {
                if (!path[u][v]) continue;
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    stack.push_back(v);
                } else if (color[v] == color[u]) {
                    cout << "impossible";
                    return 0;
                }
            }
        }

        cnts.push_back(cnt1);
        groups.push_back(comp);
    }

    int k = (int)cnts.size();
    vector<vector<char>> dp(k + 1, vector<char>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < k; ++i) {
        int c1 = cnts[i];
        int c2 = (int)groups[i].size() - c1;
        for (int j = 0; j <= n; ++j) if (dp[i][j]) {
            dp[i + 1][j + c1] = 1;
            dp[i + 1][j + c2] = 1;
        }
    }

    if (!dp[k][n / 2]) {
        cout << "impossible";
        return 0;
    }

    int cur = n / 2;
    vector<int> chosen(k, 0);
    for (int i = k - 1; i >= 0; --i) {
        int c1 = cnts[i];
        int c2 = (int)groups[i].size() - c1;
        if (cur >= c1 && dp[i][cur - c1]) {
            chosen[i] = c1;
            cur -= c1;
        } else {
            chosen[i] = c2;
            cur -= c2;
        }
    }

    for (int i = 0; i < k; ++i) {
        if (chosen[i] != cnts[i]) {
            for (int u : groups[i]) color[u] ^= 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ("rb"[color[i]]) << '\n';
    }

    return 0;
}
