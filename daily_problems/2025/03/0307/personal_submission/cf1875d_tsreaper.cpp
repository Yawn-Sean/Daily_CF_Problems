#include <bits/stdc++.h>
#define MAXN 5000
#define INF ((int) 1e9)
using namespace std;

int n, cnt[MAXN + 10];

int f[MAXN + 10];

void solve() {
    scanf("%d", &n);
    memset(cnt, 0, sizeof(int) * (n + 3));
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x <= n) cnt[x]++;
    }

    int mex;
    for (mex = 0; mex <= n; mex++) if (cnt[mex] == 0) break;

    for (int i = 0; i <= mex; i++) f[i] = INF;
    f[mex] = 0;
    for (int i = mex - 1; i >= 0; i--) for (int j = mex; j > i; j--) f[i] = min(f[i], f[j] + j * (cnt[i] - 1) + i);
    printf("%d\n", f[0]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
