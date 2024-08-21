#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 10];

int f[MAXN + 10], g[MAXN + 10];

bool dp(int L, int R, int last) {
    if (L > R) return false;
    bool ret = false;

    if (A[L] > last) {
        if (A[L] >= A[R]) {
            if (f[L] % 2 == 1) ret = true;
        } else {
            if (!dp(L + 1, R, A[L])) ret = true;
        }
    }

    if (A[R] > last) {
        if (A[R] >= A[L]) {
            if (g[R] % 2 == 1) ret = true;
        } else {
            if (!dp(L, R - 1, A[R])) ret = true;
        }
    }

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    f[n] = 1;
    for (int i = n - 1; i > 0; i--) {
        if (A[i] < A[i + 1]) f[i] = f[i + 1] + 1;
        else f[i] = 1;
    }
    g[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (A[i] < A[i - 1]) g[i] = g[i - 1] + 1;
        else g[i] = 1;
    }

    if (dp(1, n, -1)) printf("Alice\n");
    else printf("Bob\n");
    return 0;
}
