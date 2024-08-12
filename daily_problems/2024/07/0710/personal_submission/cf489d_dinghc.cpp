#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> in(n, vector<int>());
    vector<vector<int>> out(n, vector<int>());
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d %d", &a, &b);
        a--, b--;
        in[b].push_back(a);
        out[a].push_back(b);
    }
    vector<vector<int>> cnt(n, vector<int>(n, 0));
    for (int j = 0; j < n; j++) {
        for (auto& u : in[j]) {
            for (auto& v : out[j]) {
                cnt[u][v]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int k = cnt[i][j];
                ans += k * (k - 1) / 2;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
