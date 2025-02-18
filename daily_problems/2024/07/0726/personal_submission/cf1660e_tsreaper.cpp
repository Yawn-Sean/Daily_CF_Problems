#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, ans;
char MAP[MAXN + 10][MAXN + 10];

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", MAP[i]);

    ans = n * n;
    int one = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (MAP[i][j] == '1') one++;
    for (int j = 0; j < n; j++) {
        int cnt[2] = {0};
        for (int i = 0; i < n; i++) cnt[MAP[i][(i + j) % n] - '0']++;
        ans = min(ans, cnt[0] + one - cnt[1]);
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
