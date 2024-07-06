#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, q, ans;
char s[MAXN + 10];

int f[MAXN + 10];

void upd(int i) {
    if (s[i] == '.') {
        f[i] = 1;
        if (i == 1 || s[i - 1] != '.') f[i] = 0;
    } else {
        f[i] = 0;
    }
}

int main() {
    scanf("%d%d%s", &n, &q, s + 1);
    for (int i = 1; i <= n; i++) upd(i), ans += f[i];

    while (q--) {
        int x;
        char c[3];
        scanf("%d%s", &x, c);
        s[x] = c[0];
        for (int i = x, t = 0; i <= n && t < 2; i++, t++) {
            ans -= f[i];
            upd(i);
            ans += f[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
