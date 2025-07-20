#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K;
long long A[MAXN];

int main() {
    scanf("%d%d", &n, &K); K--;
    for (int i = 0; i < n; i++) scanf("%lld", &A[i]);

    int mn = 2e9, pos;
    for (int i = 0; i < n; i++) {
        int idx = (K - i + n) % n;
        if (A[idx] < mn) mn = A[idx], pos = idx;
    }

    int dis = (K - pos + n) % n;
    long long val = 1LL * mn * n + dis;
    for (int i = 1; i <= n; i++) {
        int idx = (pos + i) % n;
        A[idx] -= mn + (i <= dis ? 1 : 0);
    }
    A[pos] = val;
    for (int i = 0; i < n; i++) printf("%lld%c", A[i], "\n "[i + 1 < n]);
    return 0;
}
