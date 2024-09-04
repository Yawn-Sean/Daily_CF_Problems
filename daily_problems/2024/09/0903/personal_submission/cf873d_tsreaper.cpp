#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K, ans[MAXN];

void gao(int l, int r, int val) {
    if (l + 1 == r) { ans[l] = val; return; }
    if (K == 0) {
        for (int i = l; i < r; i++) ans[i] = val + i - l;
        return;
    }
    int mid = (l + r) >> 1;
    K -= 2;
    gao(l, mid, val + r - mid); gao(mid, r, val);
}

int main() {
    scanf("%d%d", &n, &K);
    if (K % 2 == 0) { printf("-1\n"); return 0; }
    K--; gao(0, n, 1);
    if (K > 0) { printf("-1\n"); return 0; }
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], "\n "[i + 1 < n]);
    return 0;
}
