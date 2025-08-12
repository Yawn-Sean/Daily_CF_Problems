#include <bits/stdc++.h>
using namespace std;

long long n, ans;

int cnt[10];
long long fac[20];

void dfs1(int d, int tot, long long now) {
    if (d > 9) {
        ans += fac[tot] / now;
        return;
    }
    if (cnt[d] == 0) dfs1(d + 1, tot, now);
    else for (int i = 1; i <= cnt[d]; i++) dfs1(d + 1, tot + i, now * fac[i]);
}

void dfs2(int d, int tot, long long now) {
    if (d > 9) {
        ans -= fac[tot] / now;
        return;
    }

    if (cnt[d] == 0) dfs2(d + 1, tot, now);
    else {
        int l = 1, r = cnt[d];
        if (d == 0) l--, r--;
        for (int i = l; i <= r; i++) dfs2(d + 1, tot + i, now * fac[i]);
    }
}

int main() {
    scanf("%lld", &n);
    for (; n; n /= 10) cnt[n % 10]++;

    fac[0] = 1;
    for (int i = 1; i < 20; i++) fac[i] = fac[i - 1] * i;

    dfs1(0, 0, 1);
    if (cnt[0] > 0) dfs2(0, 0, 1);
    printf("%lld\n", ans);
    return 0;
}
