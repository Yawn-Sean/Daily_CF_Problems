#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, A[MAXN + 5];
long long ans;

int L[MAXN + 5], R[MAXN + 5];
long long f[MAXN + 5], g[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) L[i] = 0;
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        while (!stk.empty() && A[stk.top()] <= A[i]) stk.pop();
        if (!stk.empty()) L[i] = stk.top();
        stk.push(i);
    }

    for (int i = 1; i <= n; i++) R[i] = n + 1;
    while (!stk.empty()) stk.pop();
    for (int i = n; i > 0; i--) {
        while (!stk.empty() && A[stk.top()] <= A[i]) stk.pop();
        if (!stk.empty()) R[i] = stk.top();
        stk.push(i);
    }

    for (int i = 1; i <= n; i++) A[i] = (A[i] % MOD + MOD) % MOD;
    for (int i = 1; i <= n; i++) {
        f[i] = (f[i - 1] + A[i]) % MOD;
        g[i] = (g[i - 1] + 1LL * i * A[i]) % MOD;
    }

    for (int i = 1; i <= n; i++) {
        long long tmp = (g[i - 1] - g[L[i]] + MOD) % MOD;
        tmp = (tmp - (f[i - 1] - f[L[i]] + MOD) * L[i] % MOD + MOD) % MOD;
        ans = (ans + tmp * (R[i] - i)) % MOD;

        tmp = (f[R[i] - 1] - f[i] + MOD) * R[i] % MOD;
        tmp = (tmp + g[i] - g[R[i] - 1] + MOD) % MOD;
        ans = (ans + tmp * (i - L[i])) % MOD;

        ans = (ans + 1LL * A[i] * (i - L[i]) % MOD * (R[i] - i)) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
