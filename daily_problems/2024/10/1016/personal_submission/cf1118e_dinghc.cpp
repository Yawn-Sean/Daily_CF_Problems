#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k) {
    for (int d = 1; d <= k; d++) {
        for (int i = 0; i < k; i++) {
            printf("%d %d\n", i + 1, (i + d) % k + 1);
            if (--n == 0) return;
        }
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    if (n > 1LL * (k - 1) * k) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    solve(n, k);
    return 0;
}

