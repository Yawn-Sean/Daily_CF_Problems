#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, ans[MAXN + 5];

void solve(int n) {
    if (n <= 0) return;
    int base = 1 << __lg(n);
    int len = n - base + 1;
    for (int i = 0; i < len; i++) {
        ans[base + i] = base - i - 1;
        ans[base - i - 1] = base + i;
    }
    solve(base - len - 1);
}

int main() {
    scanf("%d", &n);
    solve(n);
    printf("%lld\n", 1LL * n * (n + 1));
    for (int i = 0; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}
