#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
constexpr int M = 1'000'000'007;
int a[N], b[N];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int m = n / k;
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    auto count = [] (int q, int d) {
        if (q < 0) return 0;
        return q / d + 1;
    };
    int p1 = 1;
    for (int i = 1; i < k; i++) p1 *= 10;
    int p2 = p1 * 10 - 1;
    int ans = 1;
    for (int i = 0; i < m; i++) {
        int k1 = count(b[i] * p1 - 1, a[i]);
        int k2 = count(p2, a[i]) - count((b[i] + 1) * p1 - 1, a[i]);
        ans = (1LL * ans * (k2 + k1)) % M;
    }
    printf("%d\n",  ans);
    return 0;
}

