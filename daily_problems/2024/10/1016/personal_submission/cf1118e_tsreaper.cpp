#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K; scanf("%d%d", &n, &K);
    if (1LL * K * (K - 1) < n) { printf("NO\n"); return 0; }
    printf("YES\n");
    for (int len = 1; len < K; len++) for (int i = 0; i < K; i++) {
        printf("%d %d\n", i + 1, (i + len) % K + 1);
        n--;
        if (n == 0) return 0;
    }
    return 0;
}
