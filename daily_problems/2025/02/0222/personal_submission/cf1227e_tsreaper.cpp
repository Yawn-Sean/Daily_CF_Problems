#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, m;
string MAP[MAXN + 5];

vector<int> f[MAXN + 5], g[MAXN + 5];

vector<string> calc(int lim) {
    for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= m + 1; j++) g[i][j] = 0;

    vector<string> ans(n);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans[i].push_back('.');

    int len = lim * 2 + 1;
    for (int i = len; i <= n; i++) for (int j = len; j <= m; j++) {
        int cnt = f[i][j] - f[i - len][j] - f[i][j - len] + f[i - len][j - len];
        if (cnt == len * len) {
            g[i - len + 1][j - len + 1]++;
            g[i - len + 1][j + 1]--;
            g[i + 1][j - len + 1]--;
            g[i + 1][j + 1]++;
            ans[i - lim - 1][j - lim - 1] = 'X';
        }
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) g[i][j] += g[i][j - 1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) g[i][j] += g[i - 1][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (MAP[i][j] == 'X' && g[i][j] == 0) return {};
        if (MAP[i][j] == '.' && g[i][j] > 0) return {};
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; i++) {
        MAP[i].resize(m + 3);
        f[i].resize(m + 3);
        g[i].resize(m + 3);
    }
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i].c_str() + 1);

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] = f[i][j - 1] + (MAP[i][j] == 'X' ? 1 : 0);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) f[i][j] += f[i - 1][j];

    int head = 0, tail = (min(n, m) - 1) / 2;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (calc(mid).size() > 0) head = mid;
        else tail = mid - 1;
    }

    printf("%d\n", head);
    auto ans = calc(head);
    for (auto &s : ans) printf("%s\n", s.c_str());
    return 0;
}
