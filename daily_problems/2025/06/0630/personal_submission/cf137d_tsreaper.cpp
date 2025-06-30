#include <bits/stdc++.h>
#define MAXN 500
#define INF ((int) 1e9)
using namespace std;

int n, K;
char s[MAXN + 5];

int f[MAXN + 5][MAXN + 5], from[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5];

int main() {
    scanf("%s%d", s + 1, &K); n = strlen(s + 1);

    for (int i = 1; i <= n; i++) g[i][i] = 0;
    for (int i = 1; i < n; i++) g[i][i + 1] = (s[i] == s[i + 1] ? 0 : 1);
    for (int len = 3; len <= n; len++) for (int i = 1, j = len; j <= n; i++, j++)
        g[i][j] = g[i + 1][j - 1] + (s[i] == s[j] ? 0 : 1);

    for (int i = 0; i <= n; i++) for (int j = 0; j <= K; j++) f[i][j] = INF;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= K; j++) for (int ii = 0; ii < i; ii++) {
        int t = f[ii][j - 1] + g[ii + 1][i];
        if (t < f[i][j]) f[i][j] = t, from[i][j] = ii;
    }

    int ans = INF, best = 0;
    for (int j = 1; j <= K; j++) if (f[n][j] < ans) ans = f[n][j], best = j;
    printf("%d\n", ans);
    vector<string> vec;
    for (int i = n, j = best; i > 0; ) {
        string tmp;
        for (int p = from[i][j] + 1; p <= i; p++) tmp.push_back(s[p]);
        for (int l = 0, r = tmp.size() - 1; l < r; l++, r--) if (tmp[l] != tmp[r]) tmp[r] = tmp[l];
        vec.push_back(tmp);
        i = from[i][j]; j--;
    }
    reverse(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        printf("%s", vec[i].c_str());
        if (i + 1 != vec.size()) printf("+");
        else printf("\n");
    }
    return 0;
}
