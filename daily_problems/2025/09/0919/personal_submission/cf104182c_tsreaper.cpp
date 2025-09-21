#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXP 20
using namespace std;

int n, A[MAXN + 5];
long long ans;

int f[MAXN + 5][MAXP], g[MAXN + 5], h[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) f[i][0] = h[i] = n + 1;
    for (int p = 0; p < MAXP; p++) f[n + 1][p] = n + 1;

    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && A[stk.top()] <= A[i]) {
            f[stk.top()][0] = i;
            stk.pop();
        }
        stk.push(i);
    }
    for (int i = n; i > 0; i--) {
        for (int p = 1; p < MAXP; p++) f[i][p] = f[f[i][p - 1]][p - 1];
        g[i] = g[f[i][0]] + 1;
    }

    while (!stk.empty()) stk.pop();
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && A[stk.top()] > A[i]) {
            h[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }

    for (int i = 1; i <= n; i++) {
        ans += n - i + 1 - g[i];
        if (i == 1 || A[i] < A[i - 1]) continue;

        int t = 0;
        for (int p = MAXP - 1, now = i; p >= 0; p--)
            if (f[now][p] < h[i - 1]) t |= 1 << p, now = f[now][p];
        ans -= h[i - 1] - i;
        ans += t + 1;
    }

    printf("%lld\n", ans + 1);
    return 0;
}
