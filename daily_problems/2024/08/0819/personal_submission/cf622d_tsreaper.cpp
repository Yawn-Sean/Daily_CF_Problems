#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, ans[MAXN * 2 + 10];

int main() {
    scanf("%d", &n);
    if (n & 1) {
        for (int i = 1, l = 1, r = n; i < n; i += 2, l++, r--) ans[l] = ans[r] = i;
        for (int i = 2, l = n + 2, r = n * 2; i < n; i += 2, l++, r--) ans[l] = ans[r] = i;
    } else {
        for (int i = 1, l = 1, r = n; i < n; i += 2, l++, r--) ans[l] = ans[r] = i;
        for (int i = 2, l = n + 1, r = n * 2 - 1; i < n; i += 2, l++, r--) ans[l] = ans[r] = i;
    }
    for (int i = 1; i <= n * 2; i++) printf("%d%c", ans[i] ? ans[i] : n, "\n "[i < n * 2]);
    return 0;
}
