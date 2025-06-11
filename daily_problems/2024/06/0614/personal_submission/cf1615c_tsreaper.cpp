#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n;
char s1[MAXN + 10], s2[MAXN + 10];

void gao(int x) {
    for (int i = 1; i <= n; i++) if (i != x) s1[i] ^= 1;
}

int calc() {
    int cnt[4] = {0};
    for (int i = 1; i <= n; i++) {
        int msk = (s1[i] - '0') * 2 + (s2[i] - '0');
        cnt[msk]++;
    }

    if (cnt[1] != cnt[2]) return n + 1;
    return cnt[1] * 2;
}

void solve() {
    scanf("%d%s%s", &n, s1 + 1, s2 + 1);

    int ans = calc();

    for (int i = 1; i <= n; i++) if (s1[i] == '1' && s2[i] == '0') {
        gao(i);
        ans = min(ans, calc() + 1);
        gao(i);
        break;
    }

    for (int i = 1; i <= n; i++) if (s1[i] == '1' && s2[i] == '1') {
        gao(i);
        ans = min(ans, calc() + 1);
        gao(i);
        break;
    }

    printf("%d\n", ans <= n ? ans : -1);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}
