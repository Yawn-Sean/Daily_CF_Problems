#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXA ((int) 1e6)
#define MAXP 20LL
using namespace std;
typedef pair<int, int> pii;

int n, m, q, A[MAXN + 5];

int f[MAXA + 5];
bool vis[MAXA + 5];

long long power(long long a, long long b) {
    if (a == 1) return 1;
    long long y = 1;
    while (b--) {
        y *= a;
        if (y > MAXP) break;
    }
    return min(y, MAXP);
}

long long power(long long a, long long b, int MOD) {
    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

bool solve(int x) {
    if (x == 1) return true;
    if (m == 1) return A[1] % x == 0;

    if (n == 2) {
        if (power(A[1], A[2], x) == 0) return true;
        if (power(A[2], A[1], x) == 0) return true;
        return false;
    }

    if (n == 3) {
        for (int t = 1; t <= 6; t++) {
            if (power(A[1], power(A[2], A[3]) * A[2], x) == 0) return true;
            if (power(A[2], power(A[1], A[2]) * A[3], x) == 0) return true;
            next_permutation(A + 1, A + n + 1);
        }
        return false;
    }

    return vis[f[x]];
}

int main() {
    for (int i = 1; i <= MAXA; i++) f[i] = 1;
    for (int i = 2; i <= MAXA; i++) if (f[i] == 1) for (int j = i; j <= MAXA; j += i) f[j] *= i;

    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (A[i] > 1) vis[f[A[i]]] = true;
    }
    sort(A + 1, A + n + 1, greater<int>());
    for (m = 1; A[m] > 1; m++);
    m--;

    for (int i = 1; i <= MAXA; i++) if (!vis[i])
        for (int j = i; j <= MAXA; j += i) if (vis[j]) { vis[i] = true; break; }

    while (q--) {
        int x; scanf("%d", &x);
        if (solve(x)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
