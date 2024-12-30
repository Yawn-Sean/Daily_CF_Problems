#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((int) 1e9)
using namespace std;
typedef pair<int, int> pii;

int n, m;
char s[MAXN + 10];

pii f[MAXN + 10];
int g[2][MAXN + 10];

int main() {
    scanf("%d%s%d", &n, s + 1, &m);
    if (m > n) { printf("0\n"); return 0; }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) g[j][i] = g[j][i - 1];
        if (s[i] == '?') continue;
        int t = (s[i] & 1) ^ (i & 1);
        g[t][i]++;
    }

    pii mx = {0, 0};
    for (int i = 1, j = 1; i + m - 1 <= n; i++) {
        while (i - j >= m) mx = max(mx, f[j]), j++;
        f[i] = {-INF, -INF};
        if (s[i] == 'a' || s[i] == '?') {
            int t = ('a' & 1) ^ (i & 1);
            if (g[t ^ 1][i + m - 1] - g[t ^ 1][i - 1] == 0) {
                f[i] = mx;
                f[i].first++;
                f[i].second += g[t][i + m - 1] - g[t][i - 1];
            }
        }
    }

    pii ans = {0, 0};
    for (int i = 1; i + m - 1 <= n; i++) ans = max(ans, f[i]);
    printf("%d\n", m * ans.first - ans.second);
    return 0;
}
