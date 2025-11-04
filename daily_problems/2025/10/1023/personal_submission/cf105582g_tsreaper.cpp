#include <bits/stdc++.h>
#define MAXN 35
using namespace std;

int n, X, Y, A[MAXN], B[MAXN];
long long ans;

int main() {
    scanf("%d%d%d", &n, &X, &Y);
    for (int i = 0; i < n; i++) scanf("%d%d", &A[i], &B[i]);

    int m = n / 2;
    unordered_map<int, int> mp;
    for (int i = 0; i < (1 << m); i++) {
        int x = 0, y = 0;
        for (int j = 0; j < m; j++) if (i >> j & 1) x += A[j], y += B[j];
        mp[Y * x - X * y]++;
    }

    for (int i = 0; i < (1 << (n - m)); i++) {
        int x = 0, y = 0;
        for (int j = 0; j < n - m; j++) if (i >> j & 1) x += A[j + m], y += B[j + m];
        int key = X * y - Y * x;
        if (mp.count(key)) ans += mp[key];
    }
    printf("%lld\n", ans - 1);
    return 0;
}
