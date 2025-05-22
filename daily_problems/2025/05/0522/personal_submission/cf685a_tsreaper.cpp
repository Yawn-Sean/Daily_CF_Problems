#include <bits/stdc++.h>
using namespace std;

int len(int x) {
    long long p = 1;
    for (int i = 1; ; i++) {
        p *= 7;
        if (p > x) return i;
    }
}

int gao(int x, int len) {
    int ret = 0;
    for (int i = 1; i <= len; i++, x /= 7) {
        int d = 1 << (x % 7);
        if (ret & d) return 0b1111111;
        ret |= d;
    }
    return ret;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    int ln = len(n - 1), lm = len(m - 1);
    if (ln + lm > 7) { printf("0\n"); return 0; }

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if ((gao(i, ln) & gao(j, lm)) == 0) ans++;
    printf("%d\n", ans);
    return 0;
}
