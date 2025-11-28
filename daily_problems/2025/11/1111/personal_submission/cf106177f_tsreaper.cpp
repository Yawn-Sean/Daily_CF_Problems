#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5];
long long ans;

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), A[i] %= 2;

    ans = 0;
    unordered_map<int, unordered_map<int, int>> cnt;
    cnt[0][0] = 1;
    for (int i = 1, x = 0, y = 0; i <= n; i++) {
        if (A[i]) x ^= 1, y++;
        else y--;
        ans += cnt[x][y + 1];
        ans += cnt[x ^ 1][y - 1];
        cnt[x][y]++;
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
